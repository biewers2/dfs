#include "exceptions/socket.h"


const char*
SocketException::what() const throw() {
    return "An error occurred relating to a socket operation.";
}


const char*
SocketInitException::what() const throw() {
    return "Socket failed to initialize.";
}


const char*
SocketOptionException::what() const throw() {
    return "Socket options failed to set.";
}


const char*
SocketBindException::what() const throw() {
    return "Socket failed to bind port.";
}


const char*
SocketListenException::what() const throw() {
    return "Socket failed to listen.";
}


const char*
SocketAcceptException::what() const throw() {
    return "Socket failed to accept incoming connection.";
}


const char*
SocketAddressException::what() const throw() {
    return "Socket address was invalid or not supported.";
}


const char*
SocketConnectionException::what() const throw() {
    return "Socket failed to connect to server.";
}