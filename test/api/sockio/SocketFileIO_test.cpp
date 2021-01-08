#include <thread>
#include <iostream>
#include <fstream>

#include <unistd.h>

#include <gtest/gtest.h>

#include "exceptions/fs.h"
#include "fs/DirectoryScanner.h"
#include "SocketFileIOTest.h"


static bool
fileExists(const std::string& fileName) {
    return (access(fileName.c_str(), F_OK) != -1);
}


static bool
filesAreEqual(const std::string& fileName1, const std::string& fileName2) {
    std::ifstream fileStream1(fileName1, std::ifstream::binary | std::ifstream::ate);
    std::ifstream fileStream2(fileName2, std::ifstream::binary | std::ifstream::ate);

    if (fileStream1.fail() || fileStream2.fail()) {
        return false;
    }
    if (fileStream1.tellg() != fileStream2.tellg()) {
        return false; // File sizes aren't equal.
    }

    std::filebuf* fileStream1End{ fileStream1.rdbuf() };
    fileStream1.seekg(0, std::ifstream::beg);
    fileStream2.seekg(0, std::ifstream::beg);
    return std::equal(std::istreambuf_iterator<char>(fileStream1.rdbuf()),
                      std::istreambuf_iterator<char>(fileStream1End),
                      std::istreambuf_iterator<char>(fileStream2.rdbuf()));
}


template<typename L1, typename L2>
static void
testSocketsWith(Server* server, L1 serverCode, Client* client, L2 clientCode) {
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


TEST_F(SocketFileIOTest, test_single_file) {
    testSocketsWith(
            m_server, [=]() -> void {
                try {
                    ASSERT_NO_THROW(m_reader->readDataIntoFile("server-mock-file"));
                    EXPECT_TRUE(fileExists("server-mock-file"));
                    EXPECT_TRUE(filesAreEqual("mock-fs/unit/mock-file", "server-mock-file"));
                    EXPECT_EQ(std::remove("server-mock-file"), 0);
                } catch(std::exception& e) {
                    std::cerr << e.what() << std::endl;
                }
            },
            m_client, [=]() -> void {
                try {
                    ASSERT_NO_THROW(m_sender->sendDataFromFile("mock-fs/unit/mock-file"));
                } catch(std::exception& e) {
                    std::cerr << e.what() << std::endl;
                }
            }
    );
}


TEST_F(SocketFileIOTest, test_multiple_files) {
    testSocketsWith(
            m_server, [=]() -> void {
                try {
                    ASSERT_NO_THROW(m_reader->readDataIntoFile("server-mock-file1"));
                    ASSERT_NO_THROW(m_reader->readDataIntoFile("server-mock-file2"));
                    ASSERT_NO_THROW(m_reader->readDataIntoFile("server-mock-file3"));
                    EXPECT_TRUE(fileExists("server-mock-file1"));
                    EXPECT_TRUE(fileExists("server-mock-file2"));
                    EXPECT_TRUE(fileExists("server-mock-file3"));
                    EXPECT_TRUE(filesAreEqual("mock-fs/unit/mock-file", "server-mock-file1"));
                    EXPECT_TRUE(filesAreEqual("mock-fs/unit/mock-file", "server-mock-file2"));
                    EXPECT_TRUE(filesAreEqual("mock-fs/unit/mock-file", "server-mock-file3"));
                    EXPECT_EQ(std::remove("server-mock-file1"), 0);
                    EXPECT_EQ(std::remove("server-mock-file2"), 0);
                    EXPECT_EQ(std::remove("server-mock-file3"), 0);
                } catch(std::exception& e) {
                    std::cerr << e.what() << std::endl;
                }
            },
            m_client, [=]() -> void {
                try {
                    ASSERT_NO_THROW(m_sender->sendDataFromFile("mock-fs/unit/mock-file"));
                    ASSERT_NO_THROW(m_sender->sendDataFromFile("mock-fs/unit/mock-file"));
                    ASSERT_NO_THROW(m_sender->sendDataFromFile("mock-fs/unit/mock-file"));
                } catch(std::exception& e) {
                    std::cerr << e.what() << std::endl;
                }
            }
    );
}


TEST_F(SocketFileIOTest, test_single_file_bad_format) {
    testSocketsWith(
            m_server, [=]() -> void {},
            m_client, [=]() -> void {
                ASSERT_THROW(m_sender->sendDataFromFile("file-does-not-exist"), FileOpenException);
            }
    );
}