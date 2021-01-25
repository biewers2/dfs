#ifndef __DFS_TESTING_FT_INDEX_WRITER_TEST_H__
#define __DFS_TESTING_FT_INDEX_WRITER_TEST_H__

#include <unordered_map>

#include <gtest/gtest.h>

#include "ResourceTest.h"
#include "ft/FileIndexReader.h"
#include "ft/FileIndexWriter.h"
#include "api/fs/timestamp.h"


class FTIndexWriterTest : public ResourceTest {
protected:
    void SetUp() override;
    void TearDown() override;

    std::unordered_map<std::string, timestamp_t>& indexRef();

    std::string buildResourcesPath(const std::string& pathString) override;

    FileIndex* m_index;
    FileIndexWriter* m_indexWriter;
};


#endif // __DFS_TESTING_FT_INDEX_WRITER_TEST_H__
