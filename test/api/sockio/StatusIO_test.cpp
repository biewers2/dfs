#include <gtest/gtest.h>

#include "test-util.h"
#include "exceptions/fs.h"
#include "StatusIOTest.h"


using stp::FileStatus;


TEST_F(StatusIOTest, test_single_file) {
    TEST_SERVER_CLIENT(
        [=]() -> void {
            FileStatus status;
            std::string fileName;
            ASSERT_NO_THROW(status = m_receiver->recvStatus(fileName));
            EXPECT_TRUE(!fileName.empty());
            EXPECT_EQ(status, FileStatus::GOOD);
        },
        [=]() -> void {
            ASSERT_NO_THROW(m_sender->sendStatus("test-file", FileStatus::GOOD));
        }
    );
}


TEST_F(StatusIOTest, test_all_statuses) {

    TEST_SERVER_CLIENT(
        [=]() -> void {
            FileStatus status;
            std::string fileName;

            ASSERT_NO_THROW(status = m_receiver->recvStatus(fileName));
            EXPECT_TRUE(!fileName.empty());
            EXPECT_EQ(status, FileStatus::NEWER);

            ASSERT_NO_THROW(status = m_receiver->recvStatus(fileName));
            EXPECT_TRUE(!fileName.empty());
            EXPECT_EQ(status, FileStatus::OLDER);

            ASSERT_NO_THROW(status = m_receiver->recvStatus(fileName));
            EXPECT_TRUE(!fileName.empty());
            EXPECT_EQ(status, FileStatus::GOOD);
        },
        [=]() -> void {
            ASSERT_NO_THROW(m_sender->sendStatus("test-file", FileStatus::NEWER));
            ASSERT_NO_THROW(m_sender->sendStatus("test-file", FileStatus::OLDER));
            ASSERT_NO_THROW(m_sender->sendStatus("test-file", FileStatus::GOOD));
        }
    );
}
