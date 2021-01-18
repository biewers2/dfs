#include "api/fs/file.h"
#include "IndexFileIterator.h"
#include "FileTimeIndexer.h"


FileTimeIndexer::FileTimeIndexer(const std::string& indexFileName, int cacheSize) {
    m_cacheSize = cacheSize;
    m_cache = new fileTimestampIndex_t();
    m_cacheIndexArray = new std::string[m_cacheSize]{ 0 };
    m_nextToReplaceInCache = 0;
    m_indexFileName = indexFileName;
}


FileTimeIndexer::~FileTimeIndexer() {
    writeOutCache();
    delete m_cache;
}


timestamp_t
FileTimeIndexer::retrieveFromFile(const std::string& fileName) {
    fileTimestampPair_t indexedItem;

    IndexFileIterator iterator(m_indexFileName);
    while (iterator.hasNext()) {
        indexedItem = iterator.next();
        if (fileName == indexedItem.first) {
            break;
        }
    }
    iterator.~IndexFileIterator();
    writeOutCache();

    std::string fileNameToReplace = m_cacheIndexArray[m_nextToReplaceInCache];
    m_cacheIndexArray[m_nextToReplaceInCache] = indexedItem.first;
    if (m_cache->count(fileNameToReplace) > 0) {
        m_cache->erase(fileNameToReplace);
    }
    m_cache->insert(indexedItem);

    if (++m_nextToReplaceInCache > m_cacheSize)  {
        m_nextToReplaceInCache = 0;
    }
}


void
FileTimeIndexer::writeOutCache() {
    fileTimestampIndex_t* tempCache = new fileTimestampIndex_t(*m_cache);

    IndexFileIterator iterator(m_indexFileName);
    while (iterator.hasNext()) {
        const fileTimestampPair_t &indexedItem{iterator.next()};
        if (tempCache->count(indexedItem.first) > 0) {
            tempCache->erase(indexedItem.first);
        }
    }
    iterator.~IndexFileIterator();

    std::ofstream indexFileStream(m_indexFileName);
    for (const fileTimestampPair_t& indexableItem : *tempCache) {
        indexFileStream << indexableItem.first << ' ' << indexableItem.second << '\n';
    }
    indexFileStream.close();

    delete tempCache;
}


void
FileTimeIndexer::index(const std::string &fileName) {
    index(fileName, getLastModified(fileName));
}


void
FileTimeIndexer::index(const std::string &fileName, const timestamp_t &timestamp) {

}


bool
FileTimeIndexer::contains(const std::string &fileName) {
    if (m_cache->count(fileName) > 0) {
        return true;
    }
    return retrieveFromFile(fileName) != EMPTY_TIMESTAMP;
}


timestamp_t
FileTimeIndexer::get(const std::string &fileName) {
    if (m_cache->count(fileName) > 0) {
        return m_cache->at(fileName);
    }
    return retrieveFromFile(fileName);
}


void
FileTimeIndexer::remove(const std::string &fileName) {

}
