#include <iostream>

#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "exceptions/socket.h"
#include "util/overlap.h"

#include "Server.h"


void Server::initSocket(const int options, const int port) {
    this->socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (this->socketFd < 0) {
        throw SocketInitException();
    }

    int optionsStatus = setsockopt(this->socketFd, SOL_SOCKET, SO_REUSEADDR|SO_REUSEPORT, &options, sizeof(options));
    if (optionsStatus != 0) {
        throw SocketOptionException();
    }

    this->address.sin_family = AF_INET;
    this->address.sin_addr.s_addr = INADDR_ANY;
    this->address.sin_port = htons(port);
    int bindStatus = bind(socketFd, (struct sockaddr*)&address, addressLength);
    if (bindStatus < 0) {
        throw SocketBindException();
    }
}


bool Server::listenAndAccept() {
    int listenStatus = listen(socketFd, 3);
    if (listenStatus < 0) {
        throw SocketListenException();
    }
    this->clientSocketFd = accept(socketFd, (struct sockaddr*)&address, &addressLength);
    if (this->clientSocketFd < 0) {
        throw SocketAcceptException();
    }
    return true;
}


void Server::send(const void* data, const size_t dataSize) {
    csock::send(this->clientSocketFd, data, dataSize, 0);
}


ssize_t Server::read(char* buffer, const size_t bufferSize) {
    return csock::read(this->clientSocketFd, buffer, bufferSize);
}
