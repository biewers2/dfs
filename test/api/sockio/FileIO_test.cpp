#include <gtest/gtest.h>

#include "api/fs/file.h"
#include "test-util.h"
#include "exceptions/fs.h"
#include "FileIOTest.h"


TEST_F(FileIOTest, test_single_file) {
    TEST_SERVER_CLIENT(
        [=]() -> void {
            ASSERT_NO_THROW(m_receiver->recvDataIntoFile("server-mock-file"));
            EXPECT_TRUE(fileExists("server-mock-file"));
            EXPECT_TRUE(filesAreEqual("mock-fs/unit/mock-file", "server-mock-file"));
            EXPECT_EQ(std::remove("server-mock-file"), 0);
        },
        [=]() -> void {
            ASSERT_NO_THROW(m_sender->sendDataFromFile("mock-fs/unit/mock-file"));
        }
    );
}


TEST_F(FileIOTest, test_multiple_files) {
    const int NUM_FILES{ 10 };

    TEST_SERVER_CLIENT(
        [=]() -> void {
            for (int i{ 0 }; i < NUM_FILES; ++i) {
                ASSERT_NO_THROW(m_receiver->recvDataIntoFile("server-mock-file"));
                EXPECT_TRUE(fileExists("server-mock-file"));
                EXPECT_TRUE(filesAreEqual("mock-fs/unit/mock-file", "server-mock-file"));
                EXPECT_EQ(std::remove("server-mock-file"), 0);
            }
        },
        [=]() -> void {
            for (int i{ 0 }; i < NUM_FILES; ++i) {
                ASSERT_NO_THROW(m_sender->sendDataFromFile("mock-fs/unit/mock-file"));
            }
        }
    );
}


TEST_F(FileIOTest, test_single_file_bad_format) {
    TEST_SERVER_CLIENT(
        [=]() -> void {},
        [=]() -> void {
            ASSERT_THROW(m_sender->sendDataFromFile("file-does-not-exist"), FileOpenException);
        }
    );
}