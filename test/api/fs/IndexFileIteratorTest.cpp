#include "ft/IndexFileIterator.h"
#include "IndexFileIteratorTest.h"


void
IndexFileIteratorTest::SetUp() {
    m_iterator = new IndexFileIterator("mock-fs/mock-index-file");
}


void
IndexFileIteratorTest::TearDown() {
    delete m_iterator;
}
