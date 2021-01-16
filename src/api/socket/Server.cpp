#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "exceptions/socket.h"
#include "Server.h"


void
Server::initSocket(const int options, const int port) {
    m_socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (m_socketFd < 0) {
        throw SocketInitException();
    }

    int optionsStatus = setsockopt(m_socketFd, SOL_SOCKET, SO_REUSEADDR|SO_REUSEPORT, &options, sizeof(options));
    if (optionsStatus != 0) {
        throw SocketOptionException();
    }

    m_address.sin_family = AF_INET;
    m_address.sin_addr.s_addr = INADDR_ANY;
    m_address.sin_port = htons(port);
    int bindStatus = bind(m_socketFd, (struct sockaddr*)&m_address, ADDRESS_LENGTH);
    if (bindStatus < 0) {
        throw SocketBindException();
    }
}


bool
Server::listenAndAccept() {
    socklen_t addressLength{ ADDRESS_LENGTH };

    int listenStatus = listen(m_socketFd, 3);
    if (listenStatus < 0) {
        throw SocketListenException();
    }

    m_clientSocketFd = accept(m_socketFd, (struct sockaddr*)&m_address, &addressLength);
    if (m_clientSocketFd < 0) {
        throw SocketAcceptException();
    }

    return true;
}


void
Server::send(const void* data, const size_t dataSize) {
    ::send(m_clientSocketFd, data, dataSize, 0);
}


ssize_t
Server::recv(void* buffer, const size_t bufferSize) {
    return ::read(m_clientSocketFd, buffer, bufferSize);
}


void
Server::close() {
    ::close(m_socketFd);
}
