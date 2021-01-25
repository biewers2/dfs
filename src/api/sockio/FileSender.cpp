#include <fstream>
#include <string>

#include "exceptions/fs.h"
#include "protocols/ftp.h"
#include "api/fs/file.h"
#include "Socket.h"
#include "FileSender.h"


FileSender::FileSender(Socket* socket) {
    this->m_socket = socket;
}


void FileSender::sendDataFromFile(const std::string& fileName) {
    std::ifstream inputStream(fileName);
    if (!inputStream.is_open()) {
        throw FileOpenException();
    }

    ftp::header_t header{ file::getSizeOfFile(fileName) };
    this->m_socket->send(&header, ftp::HEADER_SIZE);

    char buffer[BUFFER_SIZE];
    size_t bytesToRead{ header.fileSize };
    while (true) {
        if (bytesToRead >= BUFFER_SIZE) {
            inputStream.read(buffer, BUFFER_SIZE);
            this->m_socket->send(buffer, BUFFER_SIZE);
        } else {
            inputStream.read(buffer, bytesToRead);
            this->m_socket->send(buffer, bytesToRead);
            break;
        }
        bytesToRead -= BUFFER_SIZE;
    }

    inputStream.close();
}
