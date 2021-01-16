#ifndef __DFS_TESTING_HASH_IO_TEST_H__
#define __DFS_TESTING_HASH_IO_TEST_H__

#include <string>

#include <gtest/gtest.h>

#include "socket/Server.h"
#include "socket/Client.h"
#include "sockio/HashReceiver.h"
#include "sockio/HashSender.h"


class HashIOTest : public ::testing::Test {

protected:
    void SetUp() override;
    void TearDown() override;

    Server* m_server;
    Client* m_client;

    HashReceiver* m_receiver;
    HashSender* m_sender;
};


#endif // __DFS_TESTING_HASH_IO_TEST_H__
