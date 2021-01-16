#include <string>

#include "socket/Server.h"
#include "socket/Client.h"
#include "sockio/StatusReceiver.h"
#include "sockio/StatusSender.h"
#include "StatusIOTest.h"


void
StatusIOTest::SetUp() {
    m_server = new Server();
    m_receiver = new StatusReceiver(m_server);

    m_client = new Client();
    m_sender = new StatusSender(m_client);
}


void
StatusIOTest::TearDown() {
    delete m_server;
    delete m_receiver;

    delete m_client;
    delete m_sender;
}

