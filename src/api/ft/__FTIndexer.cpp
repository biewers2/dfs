#include <algorithm>
#include <map>

#include "api/fs/file.h"
#include "exceptions/fs.h"
#include "IndexFileIterator.h"
#include "__FTIndexer.h"


__FTIndexer::__FTIndexer(const std::string& indexFileName, int cacheSize) {
    m_cacheSize = cacheSize;
    m_cacheQueue = new FTQueue();
    m_indexFileName = indexFileName;

    // Create file if non-existent
    std::ofstream tmpStream(m_indexFileName);
    if (!tmpStream.is_open()) {
        throw FileOpenException();
    }
    tmpStream.close();
}


__FTIndexer::~__FTIndexer() {
    writeCacheToIndex();
    delete m_cacheQueue;
}


void
__FTIndexer::placeInCache(const ftPair_t& entry) {
    ftIterator_t entryPosition{ m_cacheQueue->find(entry.first) };
    if (entryPosition != m_cacheQueue->end()) {
        m_cacheQueue->set(entryPosition, entry.second);
    } else {
        m_cacheQueue->enqueue(entry);
        if (m_cacheQueue->size() > m_cacheSize) {
            writeCacheEntryToIndex(m_cacheQueue->dequeue());
        }
    }
}


timestamp_t
__FTIndexer::retrieveFromIndexFile(const std::string& fileNameKey) {
    ftPair_t entry;

    IndexFileIterator iterator(m_indexFileName);
    while (iterator.hasNext()) {
        entry = iterator.next();
        if (fileNameKey == entry.first) {
            break;
        }
    }
    iterator.close();

    writeCacheToIndex();
    placeInCache(entry);

    return entry.second;
}


void
__FTIndexer::eraseFromIndexFile(const std::string& fileNameKey) {
    eraseFromIndexFile(std::vector<std::string>{ fileNameKey });
}


void
__FTIndexer::eraseFromIndexFile(std::vector<std::string> fileNameKeys) {
    std::ofstream tempIndexFileStream(m_indexFileName + ".tmp");
    if (!tempIndexFileStream.is_open()) {
        throw FileOpenException();
    }
    IndexFileIterator iterator(m_indexFileName);
    while (iterator.hasNext()) {
        const ftPair_t& fileEntry{ iterator.next() };
        auto entryPosition{ std::find(fileNameKeys.begin(), fileNameKeys.end(), fileEntry.first) };
        if (entryPosition == fileNameKeys.end()) {
            tempIndexFileStream << fileEntry.first << ' ' << fileEntry.second << '\n';
        } else {
            fileNameKeys.erase(entryPosition);
        }
    }
    iterator.close();
    tempIndexFileStream.close();

    std::remove(m_indexFileName.c_str());
    std::rename((m_indexFileName + ".tmp").c_str(), m_indexFileName.c_str());
}


void
__FTIndexer::writeCacheEntryToIndex(const ftPair_t& entry) {
    eraseFromIndexFile(entry.first);
    std::ofstream indexFileStream(m_indexFileName);
    if (!indexFileStream.is_open()) {
        throw FileOpenException();
    }
    indexFileStream << entry.first << ' ' << entry.second << '\n';
    indexFileStream.close();
}


void
__FTIndexer::writeCacheToIndex() {
    FTQueue* tempCache = new FTQueue(*m_cacheQueue);

    // Remove overlap between tempCache and index file.
    IndexFileIterator iterator(m_indexFileName);
    while (iterator.hasNext()) {
        const ftPair_t& entry{iterator.next()};

        ftIterator_t entryPosition = tempCache->find(entry.first);
        if (entryPosition != tempCache->end()) {
            tempCache->erase(entryPosition);
        }
    }
    iterator.close();

    // Write remaining entries to index file.
    std::ofstream indexFileStream(m_indexFileName);
    if (!indexFileStream.is_open()) {
        throw FileOpenException();
    }
    for (const auto& entry : *tempCache) {
        indexFileStream << entry.first << ' ' << entry.second << '\n';
    }
    indexFileStream.close();

    delete tempCache;
}




void
__FTIndexer::index(const std::string& fileName) {
    index(fileName, getLastModified(fileName));
}


void
__FTIndexer::index(const std::string& fileName, const timestamp_t& timestamp) {
    placeInCache(ftPair_t(fileName, timestamp));
}


bool
__FTIndexer::contains(const std::string& fileName) {
    if (m_cacheQueue->contains(fileName)) {
        return true;
    } else {
        return retrieveFromIndexFile(fileName) != EMPTY_TIMESTAMP;
    }
}


timestamp_t
__FTIndexer::get(const std::string& fileName) {
    ftIterator_t entryIter{ m_cacheQueue->find(fileName) };
    if (entryIter != m_cacheQueue->end()) {
        return entryIter->second;
    } else {
        return retrieveFromIndexFile(fileName);
    }
}


void
__FTIndexer::erase(const std::string& fileName) {
    ftIterator_t entryPosition{ m_cacheQueue->find(fileName) };
    if (entryPosition != m_cacheQueue->end()) {
        m_cacheQueue->erase(entryPosition);
    } else {
        eraseFromIndexFile(fileName);
    }
}
