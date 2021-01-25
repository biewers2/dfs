#include <string>

#include "FileIndex.h"
#include "FileIndexer.h"


FileIndexer::FileIndexer(FileIndex* index) {
    m_indexObject = index;
}


FileIndex::FileIndexData
FileIndexer::getData(const std::string& fileName) {
    if (m_indexObject->m_index->count(fileName) > 0) {
        return m_indexObject->m_index->at(fileName);
    } else {
        return FileIndex::bundleData(EMPTY_TIMESTAMP, "");
    }
}


timestamp_t
FileIndexer::getTimestamp(const std::string& fileName) {
    return getData(fileName).timestamp;
}


hashString_t
FileIndexer::getHashString(const std::string& fileName) {
    return getData(fileName).hash;
}


void
FileIndexer::insert(const std::string& fileName, const timestamp_t& timestamp, const hashString_t& hash) {
    m_indexObject->m_index->insert(std::pair<std::string, FileIndex::FileIndexData>(fileName, FileIndex::bundleData(timestamp, hash)));
}


void
FileIndexer::erase(const std::string& fileName) {
    m_indexObject->m_index->erase(fileName);
}


bool
FileIndexer::contains(const std::string& fileName) {
    return m_indexObject->m_index->count(fileName) > 0;
}
