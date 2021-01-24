#include <string>

#include "ft/FTIndexer.h"
#include "FTIndexWriterTest.h"


void
FTIndexWriterTest::SetUp() {
    m_index = new FTIndex();
    m_indexWriter = new FTIndexWriter(m_index);
}


void
FTIndexWriterTest::TearDown() {
    delete m_indexWriter;
    delete m_index;
}


std::string FTIndexWriterTest::buildResourcesPath(const std::string& pathString) {
    return "resources/FTIndexWriterTest/" + pathString;
}


std::unordered_map<std::string, timestamp_t>&
FTIndexWriterTest::indexRef() {
    return *m_index->index;
}
