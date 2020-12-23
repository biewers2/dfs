#include <fstream>
#include <string>

#include "api/ftp.h"
#include "api/Socket.h"
#include "SocketFileReader.h"

#define BUFFER_SIZE (1024)


SocketFileReader::SocketFileReader(Socket* socket) {
    this->socket = socket;
}


void SocketFileReader::readDataIntoFile(const char* fileName) {
    std::ofstream dataStream(fileName);
    std::streamsize fileSize;
    this->socket->read((char*)&fileSize, FTP_HEADER_SIZE);

    std::streamsize bytesToRead{ fileSize };
    char* buffer = new char[BUFFER_SIZE];
    while (bytesToRead > 0) {
        if (bytesToRead >= BUFFER_SIZE) {
            this->socket->read(buffer, BUFFER_SIZE);
            dataStream.write(buffer, BUFFER_SIZE);
        } else {
            this->socket->read(buffer, bytesToRead);
            dataStream.write(buffer, bytesToRead);
        }
        bytesToRead -= BUFFER_SIZE;
    }
    delete[] buffer;

    dataStream.close();
}
