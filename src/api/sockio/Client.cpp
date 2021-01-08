#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "exceptions/socket.h"

#include "sockio/Client.h"


void
Client::initSocket(const std::string& address, const int port) {
    m_socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (m_socketFd < 0) {
        throw SocketInitException();
    }
    m_serverAddress.sin_family = AF_INET;
    m_serverAddress.sin_port = htons(port);

    int ipConversionStatus = inet_pton(AF_INET, address.c_str(), &m_serverAddress.sin_addr);
    if (ipConversionStatus <= 0) {
        throw SocketAddressException();
    }
}


void
Client::connect() {
    int connectionStatus = ::connect(m_socketFd, (struct sockaddr*)&m_serverAddress, ADDRESS_LENGTH);
    if (connectionStatus < 0) {
        throw SocketConnectionException();
    }
}


void
Client::send(const void* data, const size_t dataSize) {
    ::send(m_socketFd, data, dataSize, 0);
}


ssize_t
Client::read(char* buffer, const size_t bufferSize) {
    return ::read(m_socketFd, buffer, bufferSize);
}


void
Client::close() {
    ::close(m_socketFd);
}