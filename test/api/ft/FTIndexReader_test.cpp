#include <exception>
#include <string>

#include <gtest/gtest.h>

#include "test-util.h"
#include "api/fs/file.h"
#include "FTIndexReaderTest.h"

/*
 * read empty file
 * read single
 * read multiple
 * read invalid (read 3 lines)
 */


TEST_F(FTIndexReaderTest, test_read_empty) {
    m_indexReader->setInputFile(READER_FILE_NAME_BASE + "empty");
    ASSERT_NO_THROW(m_indexReader->read());
    ASSERT_TRUE(indexRef().empty());
}


TEST_F(FTIndexReaderTest, test_read_single) {
    m_indexReader->setInputFile(READER_FILE_NAME_BASE + "single");
    ASSERT_NO_THROW(m_indexReader->read());
    ASSERT_EQ(indexRef().size(), 1);
    ASSERT_TRUE(indexRef().count("file0") > 0);
    ASSERT_TRUE(indexRef().at("file0") == (timestamp_t{ .tv_sec=123, .tv_nsec=456 }));
}


TEST_F(FTIndexReaderTest, test_read_multiple) {
    m_indexReader->setInputFile(READER_FILE_NAME_BASE + "multiple");
    ASSERT_NO_THROW(m_indexReader->read());
    ASSERT_EQ(indexRef().size(), 5);
    ASSERT_TRUE(indexRef().count("file0") > 0);
    ASSERT_TRUE(indexRef().count("file1") > 0);
    ASSERT_TRUE(indexRef().count("file2") > 0);
    ASSERT_TRUE(indexRef().count("file3") > 0);
    ASSERT_TRUE(indexRef().count("file4") > 0);
    ASSERT_TRUE(indexRef().at("file0") == (timestamp_t{ .tv_sec=333, .tv_nsec=555 }));
    ASSERT_TRUE(indexRef().at("file1") == (timestamp_t{ .tv_sec=123, .tv_nsec=456 }));
    ASSERT_TRUE(indexRef().at("file2") == (timestamp_t{ .tv_sec=100, .tv_nsec=200 }));
    ASSERT_TRUE(indexRef().at("file3") == (timestamp_t{ .tv_sec=902, .tv_nsec=513 }));
    ASSERT_TRUE(indexRef().at("file4") == (timestamp_t{ .tv_sec=135, .tv_nsec=246 }));
}


TEST_F(FTIndexReaderTest, test_read_invalid) {
    m_indexReader->setInputFile(READER_FILE_NAME_BASE + "invalid");
    ASSERT_NO_THROW(m_indexReader->read());
    ASSERT_EQ(indexRef().size(), 3);
    ASSERT_TRUE(indexRef().count("file0") > 0);
    ASSERT_TRUE(indexRef().count("file3") > 0);
    ASSERT_TRUE(indexRef().count("file4") > 0);
    ASSERT_TRUE(indexRef().at("file0") == (timestamp_t{ .tv_sec=333, .tv_nsec=555 }));
    ASSERT_TRUE(indexRef().at("file3") == (timestamp_t{ .tv_sec=902, .tv_nsec=513 }));
    ASSERT_TRUE(indexRef().at("file4") == (timestamp_t{ .tv_sec=135, .tv_nsec=246 }));
}