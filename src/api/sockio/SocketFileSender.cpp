#include <fstream>
#include <string>
#include <cstdio>

#include "exceptions/fs.h"
#include "api/ftp.h"
#include "api/file.h"
#include "SocketFileSender.h"

#define BUFFER_SIZE (1024)


SocketFileSender::SocketFileSender(Socket* socket) {
    this->socket = socket;
}


void SocketFileSender::sendDataFromFile(const char* fileName) {
    std::ifstream inputStream(fileName);
    if (!inputStream.is_open()) {
        throw FileOpenException();
    }

    std::streamsize fileSize{ (std::streamsize)getSizeOfFile(fileName) };
    this->socket->send(&fileSize, FTP_HEADER_SIZE);

    std::streamsize bytesToRead{ fileSize };
    char* buffer = new char[BUFFER_SIZE];
    while (bytesToRead > 0) {
        if (bytesToRead >= BUFFER_SIZE) {
            inputStream.read(buffer, BUFFER_SIZE);
            this->socket->send(buffer, BUFFER_SIZE);
        } else {
            inputStream.read(buffer, bytesToRead);
            this->socket->send(buffer, bytesToRead);
        }
        bytesToRead -= BUFFER_SIZE;
    }
    delete[] buffer;

    inputStream.close();
}