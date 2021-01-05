#include <thread>

#include <gtest/gtest.h>

#include "SocketFileIOTest.h"

template<typename L1, typename L2>
void testSocketsWith(Server* server, L1 serverCode, Client* client, L2 clientCode) {
    std::thread serverThread([=]() {
        server->initSocket(1, 8080);
        server->listenAndAccept();
        serverCode();
        server->close();
    });
    std::thread clientThread([=]() {
        client->initSocket("127.0.0.1", 8080);
        client->connect();
        clientCode();
        client->close();
    });
    serverThread.join();
    clientThread.join();
}


TEST_F(SocketFileIOTest, test_simple) {
    testSocketsWith(
            m_server, [=]() -> void {
                m_reader->readDataIntoFile(Path("mock-fs/unit/server-mock-file"));
            },
            m_client, [=]() -> void {
                m_sender->sendDataFromFile(Path("mock-fs/unit/mock-file"));
            }
    );
}