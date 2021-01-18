#ifndef __DFS_TESTING_FILE_TIME_INDEXER_TEST_H__
#define __DFS_TESTING_FILE_TIME_INDEXER_TEST_H__

#include <string>

#include <gtest/gtest.h>

#include "fs/DirectoryScanner.h"


class FileTimeIndexerTest : public ::testing::Test {
protected:
    void SetUp() override;
    void TearDown() override;

    FileTimeIndexer* m_indexer;
};


#endif // __DFS_TESTING_FILE_TIME_INDEXER_TEST_H__
