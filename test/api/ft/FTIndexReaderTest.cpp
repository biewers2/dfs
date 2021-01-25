#include <string>

#include "ft/FileIndexer.h"
#include "FTIndexReaderTest.h"


void
FTIndexReaderTest::SetUp() {
    m_index = new FileIndex();
    m_indexReader = new FileIndexReader(m_index);
}


void
FTIndexReaderTest::TearDown() {
    delete m_indexReader;
    delete m_index;
}


std::string FTIndexReaderTest::buildResourcesPath(const std::string& pathString) {
    return "resources/FTIndexReaderTest/" + pathString;
}


const std::unordered_map<std::string, timestamp_t>&
FTIndexReaderTest::indexRef() {
    return *m_index->index;
}
