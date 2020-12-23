#include <cstdlib>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "exceptions/socket.h"
#include "util/overlap.h"

#include "api/Socket.h"

#include "Client.h"


void Client::initSocket(const char* address, const int port) {
    this->socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (this->socketFd < 0) {
        throw SocketInitException();
    }
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);

    int ipConversionStatus = inet_pton(AF_INET, address, &serverAddress.sin_addr);
    if (ipConversionStatus <= 0) {
        throw SocketAddressException();
    }
}


void Client::connect() {
    int connectionStatus = csock::connect(this->socketFd, (struct sockaddr*)&this->serverAddress, sizeof(this->serverAddress));
    if (connectionStatus < 0) {
        throw SocketConnectionException();
    }
}


void Client::send(const void* data, const size_t dataSize) {
    csock::send(this->socketFd, data, dataSize, 0);
}


ssize_t Client::read(char* buffer, const size_t bufferSize) {
    return csock::read(this->socketFd, buffer, bufferSize);
}
