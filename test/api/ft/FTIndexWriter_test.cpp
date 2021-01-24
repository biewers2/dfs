#include <exception>
#include <string>

#include <gtest/gtest.h>

#include "api/fs/file.h"
#include "FTIndexWriterTest.h"


TEST_F(FTIndexWriterTest, test_write_empty) {
    m_indexWriter->setInputFile(buildResourcesPath("empty"));
    ASSERT_NO_THROW(m_indexWriter->write());
    ASSERT_EQ(hashContents(WRITER_FILE_NAME_BASE + "empty"), hashContents(COMPARE_FILE_NAME_BASE + "empty"));
}


TEST_F(FTIndexWriterTest, test_write_single) {
    m_indexWriter->setInputFile(WRITER_FILE_NAME_BASE + "single");
    indexRef().insert({
        { "file0", (timestamp_t{ .tv_sec=123, .tv_nsec=456 }) }
    });
    ASSERT_NO_THROW(m_indexWriter->write());
    ASSERT_EQ(hashContents(WRITER_FILE_NAME_BASE + "single"), hashContents(COMPARE_FILE_NAME_BASE + "single"));
}


TEST_F(FTIndexWriterTest, test_write_multiple) {
    m_indexWriter->setInputFile(WRITER_FILE_NAME_BASE + "multiple");
    indexRef().insert({
        { "file0", (timestamp_t{ .tv_sec=333, .tv_nsec=555 }) },
        { "file1", (timestamp_t{ .tv_sec=123, .tv_nsec=456 }) },
        { "file2", (timestamp_t{ .tv_sec=100, .tv_nsec=200 }) },
        { "file3", (timestamp_t{ .tv_sec=902, .tv_nsec=513 }) },
        { "file4", (timestamp_t{ .tv_sec=135, .tv_nsec=246 }) }
    });
    ASSERT_NO_THROW(m_indexWriter->write());
    ASSERT_EQ(hashContents(WRITER_FILE_NAME_BASE + "multiple"), hashContents(COMPARE_FILE_NAME_BASE + "multiple"));
}


TEST_F(FTIndexWriterTest, test_write_invalid) {
    m_indexWriter->setInputFile(WRITER_FILE_NAME_BASE + "invalid");
    indexRef().insert({
        { "file0", (timestamp_t{ .tv_sec=333, .tv_nsec=555 }) },
        { "file3", (timestamp_t{ .tv_sec=902, .tv_nsec=513 }) },
        { "file4", (timestamp_t{ .tv_sec=135, .tv_nsec=246 }) }
    });
    ASSERT_NO_THROW(m_indexWriter->write());
    ASSERT_EQ(hashContents(WRITER_FILE_NAME_BASE + "invalid"), hashContents(COMPARE_FILE_NAME_BASE + "invalid"));
}