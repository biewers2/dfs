#include <exception>

#include <gtest/gtest.h>

#include "test-util.h"
#include "api/fs/file.h"
#include "FTIndexWriterTest.h"


TEST_F(FTIndexWriterTest, test_write_empty) {
    m_indexWriter->setOutputFile(buildResourcesPath("empty"));
    ASSERT_NO_THROW(m_indexWriter->write());
    ASSERT_TRUE(fileExists(buildResourcesPath("empty")));
    deleteFile(buildResourcesPath("empty"));
}


TEST_F(FTIndexWriterTest, test_write_single) {
    m_indexWriter->setOutputFile(buildResourcesPath("single"));
    indexRef().insert({
        { "file0", (timestamp_t{ .tv_sec=123, .tv_nsec=456 }) }
    });
    ASSERT_NO_THROW(m_indexWriter->write());
    ASSERT_TRUE(fileExists(buildResourcesPath("single")));
    deleteFile(buildResourcesPath("single"));
}


TEST_F(FTIndexWriterTest, test_write_multiple) {
    m_indexWriter->setOutputFile(buildResourcesPath("multiple"));
    indexRef().insert({
        { "file0", (timestamp_t{ .tv_sec=333, .tv_nsec=555 }) },
        { "file1", (timestamp_t{ .tv_sec=123, .tv_nsec=456 }) },
        { "file2", (timestamp_t{ .tv_sec=100, .tv_nsec=200 }) },
        { "file3", (timestamp_t{ .tv_sec=902, .tv_nsec=513 }) },
        { "file4", (timestamp_t{ .tv_sec=135, .tv_nsec=246 }) }
    });
    ASSERT_NO_THROW(m_indexWriter->write());
    ASSERT_TRUE(fileExists(buildResourcesPath("multiple")));
    deleteFile(buildResourcesPath("multiple"));
}
