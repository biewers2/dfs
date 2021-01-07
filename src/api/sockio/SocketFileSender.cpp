#include <fstream>
#include <string>

#include "exceptions/fs.h"
#include "api/ftp.h"
#include "SocketFileSender.h"

#define BUFFER_SIZE (1024)


SocketFileSender::SocketFileSender(Socket* socket) {
    this->socket = socket;
}


void SocketFileSender::sendDataFromFile(Path path) {
    std::ifstream dataStream(path.asString());
    if (!dataStream.is_open()) {
        throw FStreamException();
    }
    std::streamsize fileSize = getFileSizeFromStream(dataStream);
    this->socket->send(&fileSize, FTP_HEADER_SIZE);

    std::streamsize bytesToRead{ fileSize };
    char* buffer = new char[BUFFER_SIZE];
    while (bytesToRead > 0) {
        if (bytesToRead >= BUFFER_SIZE) {
            dataStream.read(buffer, BUFFER_SIZE);
            this->socket->send(buffer, BUFFER_SIZE);
        } else {
            dataStream.read(buffer, bytesToRead);
            this->socket->send(buffer, bytesToRead);
        }
        bytesToRead -= BUFFER_SIZE;
    }
    delete[] buffer;

    dataStream.close();
}