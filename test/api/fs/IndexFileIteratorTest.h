#ifndef __DFS_TESTING_INDEX_FILE_ITERATOR_TEST_H__
#define __DFS_TESTING_INDEX_FILE_ITERATOR_TEST_H__

#include <gtest/gtest.h>

#include "ft/IndexFileIterator.h"


class IndexFileIteratorTest : public ::testing::Test {
protected:
    void SetUp() override;
    void TearDown() override;

    IndexFileIterator* m_iterator;
};


#endif // __DFS_TESTING_INDEX_FILE_ITERATOR_TEST_H__
