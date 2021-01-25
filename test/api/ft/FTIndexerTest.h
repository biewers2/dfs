#ifndef __DFS_TESTING_FT_INDEXER_TEST_H__
#define __DFS_TESTING_FT_INDEXER_TEST_H__

#include <gtest/gtest.h>

#include "ft/FileIndexer.h"


class FTIndexerTest : public ::testing::Test {
protected:
    void SetUp() override;
    void TearDown() override;

    const std::unordered_map<std::string, timestamp_t>& indexRef();

    const std::string FILE_NAME{ "FTIndexerTestAPI_randomFile" };

    FileIndex* m_index;
    FileIndexer* m_indexer;
};


#endif // __DFS_TESTING_FT_INDEXER_TEST_H__
