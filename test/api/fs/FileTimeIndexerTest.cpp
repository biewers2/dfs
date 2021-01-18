#include <string>

#include "fs/FileTimeIndexer.h"
#include "FileTimeIndexer.h"


void
FileTimeIndexerTest::SetUp() {
    m_indexer = new FileTimeIndexer("test-index-file", 50);
}


void
FileTimeIndexerTest::TearDown() {
    delete m_indexer;
}
