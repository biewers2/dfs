#include <string>

#include "FTIndexer.h"


FTIndexer::FTIndexer(FTIndex* index) {
    m_indexObject = index;
}


timestamp_t
FTIndexer::at(const std::string& fileName) {
    if (m_indexObject->index->count(fileName) > 0) {
        return m_indexObject->index->at(fileName);
    } else {
        return EMPTY_TIMESTAMP;
    }
}


void
FTIndexer::insert(const std::string& fileName, const timestamp_t& timestamp) {
    m_indexObject->index->insert(std::pair<std::string, timestamp_t>(fileName, timestamp));
}


void
FTIndexer::erase(const std::string& fileName) {
    m_indexObject->index->erase(fileName);
}


bool
FTIndexer::contains(const std::string& fileName) {
    return m_indexObject->index->count(fileName) > 0;
}
