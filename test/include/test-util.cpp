#include <thread>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "exceptions/fs.h"
#include "test-util.h"


bool
vectorContainsString(const std::vector<std::string>& vec, const std::string& str) {
    for (const auto& el : vec) {
        if (el == str) {
            return true;
        }
    }
    return false;
}


void
createRandomFile(const std::string& fileName, size_t sizeInBytes) {
    std::ofstream outputStream(fileName);
    if (!outputStream.is_open()) {
        throw FileOpenException();
    }

    for (int i{ 0 }; i < sizeInBytes; ++i) {
        outputStream << (char) rand();
    }

    outputStream.close();
}


void
deleteFile(const std::string& fileName) {
    if (std::remove(fileName.c_str()) != 0) {
        throw FileException();
    }
}


void
touchFile(const std::string& fileName) {
    std::ofstream(fileName).close();
}


bool
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


void
testSocketsWith(Server* server, std::function<void(void)>& serverRoutine,
                Client* client, std::function<void(void)>& clientRoutine) {
    std::thread serverThread([=]() {
        server->initSocket(1, 8080);
        server->listenAndAccept();
        serverRoutine();
        server->close();
    });
    std::thread clientThread([=]() {
        client->initSocket("127.0.0.1", 8080);
        client->connect();
        clientRoutine();
        client->close();
    });
    serverThread.join();
    clientThread.join();
}
