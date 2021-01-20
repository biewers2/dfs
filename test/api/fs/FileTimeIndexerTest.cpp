#include <string>

#include "test-util.h"
#include "ft/__FTIndexer.h"
#include "FileTimeIndexerTest.h"


static const char* INDEX_FILE_NAME{ "FileTimeIndexerTestAPI_indexFile" };


void
FileTimeIndexerTest::SetUp() {
    m_indexer = new __FTIndexer(INDEX_FILE_NAME, 50);
}


void
FileTimeIndexerTest::TearDown() {
    delete m_indexer;
    deleteFile(INDEX_FILE_NAME);
}
