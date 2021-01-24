#include <fstream>
#include <string>

#include "exceptions/fs.h"
#include "protocols/ftp.h"
#include "Socket.h"
#include "FileReceiver.h"



FileReceiver::FileReceiver(Socket* socket) {
    this->m_socket = socket;
}


void
FileReceiver::recvDataIntoFile(const std::string& fileName) {
    std::ofstream outputStream(fileName);
    if (!outputStream.is_open()) {
        throw FileOpenException();
    }

    ftp::header_t header{};
    this->m_socket->recv((char*)&header, ftp::HEADER_SIZE);

    char buffer[BUFFER_SIZE];
    size_t bytesToRead{ header.fileSize };
    while (true) {
        if (bytesToRead >= BUFFER_SIZE) {
            this->m_socket->recv(buffer, BUFFER_SIZE);
            outputStream.write(buffer, BUFFER_SIZE);
        } else {
            this->m_socket->recv(buffer, bytesToRead);
            outputStream.write(buffer, bytesToRead);
            break;
        }
        bytesToRead -= BUFFER_SIZE;
    }

    outputStream.close();
}
