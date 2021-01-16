#ifndef __DFS_TESTING_FILE_IO_TEST_H__
#define __DFS_TESTING_FILE_IO_TEST_H__

#include <string>

#include <gtest/gtest.h>

#include "socket/Server.h"
#include "socket/Client.h"
#include "sockio/FileReceiver.h"
#include "sockio/FileSender.h"


class FileIOTest : public ::testing::Test {

protected:
    void SetUp() override;
    void TearDown() override;

    Server* m_server;
    Client* m_client;

    FileReceiver* m_receiver;
    FileSender* m_sender;
};


#endif // __DFS_TESTING_FILE_IO_TEST_H__
