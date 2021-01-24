#include <string>

#include "ft/FTIndexer.h"
#include "FTIndexerTest.h"


void
FTIndexerTest::SetUp() {
    m_index = new FTIndex();
    m_indexer = new FTIndexer(m_index);
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
