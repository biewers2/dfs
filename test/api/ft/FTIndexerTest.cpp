#include <string>

#include "ft/FileIndexer.h"
#include "FTIndexerTest.h"


void
FTIndexerTest::SetUp() {
    m_index = new FileIndex();
    m_indexer = new FileIndexer(m_index);
}


void
FTIndexerTest::TearDown() {
    delete m_indexer;
    delete m_index;
}


const std::unordered_map<std::string, timestamp_t>&
FTIndexerTest::indexRef() {
    return *m_index->index;
}
