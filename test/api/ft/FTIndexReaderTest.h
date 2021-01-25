#ifndef __DFS_TESTING_FT_INDEX_IO_TEST_H__
#define __DFS_TESTING_FT_INDEX_IO_TEST_H__

#include <unordered_map>

#include <gtest/gtest.h>

#include "ResourceTest.h"
#include "ft/FileIndexReader.h"
#include "api/fs/timestamp.h"


class FTIndexReaderTest : public ResourceTest {
protected:
    void SetUp() override;
    void TearDown() override;

    const std::unordered_map<std::string, timestamp_t>& indexRef();

    std::string buildResourcesPath(const std::string& pathString) override;

    FileIndex* m_index;
    FileIndexReader* m_indexReader;
};


#endif // __DFS_TESTING_FT_INDEX_IO_TEST_H__
