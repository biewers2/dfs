#ifndef __DFS_TESTING_SOCKET_FILE_IO_TEST_H__
#define __DFS_TESTING_SOCKET_FILE_IO_TEST_H__

#include <string>

#include <gtest/gtest.h>

#include "sockio/Server.h"
#include "sockio/Client.h"
#include "sockio/SocketFileReader.h"
#include "sockio/SocketFileSender.h"


class SocketFileIOTest : public ::testing::Test {

protected:
    void SetUp() override;
    void TearDown() override;

    Server* m_server;
    Client* m_client;

    SocketFileReader* m_reader;
    SocketFileSender* m_sender;
};


#endif // __DFS_TESTING_SOCKET_FILE_IO_TEST_H__
