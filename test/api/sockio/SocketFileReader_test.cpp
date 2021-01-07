#include <thread>
#include <iostream>

#include <unistd.h>

#include <gtest/gtest.h>

#include "fs/DirectoryScanner.h"
#include "SocketFileIOTest.h"


bool fileExists(const char* fileName) {
    return (access(fileName, F_OK) != -1);
}


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
                try {
                    m_reader->readDataIntoFile(Path("mock-fs/unit/server-mock-file"));
                    ASSERT_TRUE(fileExists("mock-fs/unit/server-mock-file"));
                } catch(std::exception& e) {
                    std::cerr << e.what() << std::endl;
                }
            },
            m_client, [=]() -> void {
                try {
                    m_sender->sendDataFromFile(Path("mock-fs/unit/mock-file"));
                } catch(std::exception& e) {
                    std::cerr << e.what() << std::endl;
                }
            }
    );
}