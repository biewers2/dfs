#include "exceptions/socket.h"


const char*
SocketException::what() const noexcept {
    return "An error occurred relating to a socket operation.";
}


const char*
SocketInitException::what() const noexcept {
    return "Socket failed to initialize.";
}



const char*
SocketOptionException::what() const noexcept {
    return m_what.c_str();
}


const char*
SocketBindException::what() const noexcept {
    return "Socket failed to bind port.";
}


const char*
SocketListenException::what() const noexcept {
    return "Socket failed to listen.";
}


const char*
SocketAcceptException::what() const noexcept {
    return "Socket failed to accept incoming connection.";
}


const char*
SocketAddressException::what() const noexcept {
    return "Socket address was invalid or not supported.";
}


const char*
SocketConnectionException::what() const noexcept {
    return "Socket failed to connect to server.";
}