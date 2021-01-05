#ifndef __DFS_EXCEPTIONS_SOCKET_H__
#define __DFS_EXCEPTIONS_SOCKET_H__

#include <exception>


class SocketInitException : public std::exception {
    virtual const char* what() const throw() {
        return "Socket failed to initialize.";
    }
};


class SocketOptionException : public std::exception {
    virtual const char* what() const throw() {
        return "Socket options failed to set.";
    }
};


class SocketBindException : public std::exception {
    virtual const char* what() const throw() {
        return "Socket failed to bind port.";
    }
};


class SocketListenException : public std::exception {
    virtual const char* what() const throw() {
        return "Socket failed to listen.";
    }
};


class SocketAcceptException : public std::exception {
    virtual const char* what() const throw() {
        return "Socket failed to accept incoming connection.";
    }
};


class SocketAddressException : public std::exception {
    virtual const char* what() const throw() {
        return "Socket address was invalid or not supported.";
    }
};


class SocketConnectionException : public std::exception {
    virtual const char* what() const throw() {
        return "Socket failed to connect to server.";
    }
};


#endif // __DFS_EXCEPTIONS_SOCKET_H__