#include <gtest/gtest.h>

#include "test-util.h"
#include "exceptions/fs.h"
#include "HashIOTest.h"


TEST_F(HashIOTest, test_single_file) {
    TEST_SERVER_CLIENT(
        [=]() -> void {
            hashString_t hashValue;
            std::string fileName;
            ASSERT_NO_THROW(hashValue = m_receiver->recvHash(fileName));
            EXPECT_STREQ(file::hashContents(fileName).c_str(), hashValue.c_str());
        },
        [=]() -> void {
            ASSERT_NO_THROW(m_sender->sendHash("resources/DirectoryScannerTest/mock-file"));
        }
    );
}


TEST_F(HashIOTest, test_multiple_files) {
    const int NUM_FILES{ 10 };

    TEST_SERVER_CLIENT(
        [=]() -> void {
            hashString_t hashValue;
            std::string fileName;
            for (int i{ 0 }; i < NUM_FILES; ++i) {
                ASSERT_NO_THROW(hashValue = m_receiver->recvHash(fileName));
                EXPECT_STREQ(file::hashContents(fileName).c_str(), hashValue.c_str());
            }
        },
        [=]() -> void {
            for (int i{ 0 }; i < NUM_FILES; ++i) {
                ASSERT_NO_THROW(m_sender->sendHash("resources/DirectoryScannerTest/mock-file"));
            }
        }
    );
}


TEST_F(HashIOTest, test_single_file_bad_format) {
    TEST_SERVER_CLIENT(
        [=]() -> void {},
        [=]() -> void {
            ASSERT_THROW(m_sender->sendHash("file-does-not-exist"), FileDoesNotExistException);
        }
    );
}