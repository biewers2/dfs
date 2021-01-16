#include "sockio/HashSender.h"
#include "sockio/HashReceiver.h"
#include "socket/Server.h"
#include "socket/Client.h"
#include "HashIOTest.h"


void
HashIOTest::SetUp() {
    m_server = new Server();
    m_receiver = new HashReceiver(m_server);

    m_client = new Client();
    m_sender = new HashSender(m_client);
}


void
HashIOTest::TearDown() {
    delete m_server;
    delete m_receiver;

    delete m_client;
    delete m_sender;
}
