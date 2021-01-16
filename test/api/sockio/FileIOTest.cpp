#include "sockio/FileSender.h"
#include "sockio/FileReceiver.h"
#include "socket/Server.h"
#include "socket/Client.h"
#include "FileIOTest.h"


void
FileIOTest::SetUp() {
    m_server = new Server();
    m_receiver = new FileReceiver(m_server);

    m_client = new Client();
    m_sender = new FileSender(m_client);
}


void
FileIOTest::TearDown() {
    delete m_server;
    delete m_receiver;

    delete m_client;
    delete m_sender;
}
