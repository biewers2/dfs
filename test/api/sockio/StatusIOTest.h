#ifndef __DFS_TESTING_STATUS_IO_TEST_H__
#define __DFS_TESTING_STATUS_IO_TEST_H__

#include <string>

#include <gtest/gtest.h>

#include "socket/Server.h"
#include "socket/Client.h"
#include "sockio/StatusReceiver.h"
#include "sockio/StatusSender.h"


class StatusIOTest : public ::testing::Test {

protected:
    void SetUp() override;
    void TearDown() override;

    Server* m_server;
    Client* m_client;

    StatusReceiver* m_receiver;
    StatusSender* m_sender;
};


#endif // __DFS_TESTING_STATUS_IO_TEST_H__
