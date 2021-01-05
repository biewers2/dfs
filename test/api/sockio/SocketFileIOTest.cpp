#include "sockio/SocketFileReader.h"
#include "sockio/Server.h"
#include "SocketFileIOTest.h"


void
SocketFileIOTest::SetUp() {
    m_server = new Server();
    m_reader = new SocketFileReader(m_server);

    m_client = new Client();
    m_sender = new SocketFileSender(m_client);
}


void
SocketFileIOTest::TearDown() {
    delete m_server;
    delete m_reader;

    delete m_client;
    delete m_sender;
}
