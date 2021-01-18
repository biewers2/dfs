#ifndef __DFS_EXCEPTIONS_SOCKET_H__
#define __DFS_EXCEPTIONS_SOCKET_H__

#include <exception>


class SocketException : public std::exception {
    virtual const char* what() const throw();
};


class SocketInitException : public SocketException {
    virtual const char* what() const throw();
};


class SocketOptionException : public SocketException {
    virtual const char* what() const throw();
};


class SocketBindException : public SocketException {
    virtual const char* what() const throw();
};


class SocketListenException : public SocketException {
    virtual const char* what() const throw();
};


class SocketAcceptException : public SocketException {
    virtual const char* what() const throw();
};


class SocketAddressException : public SocketException {
    virtual const char* what() const throw();
};


class SocketConnectionException : public SocketException {
    virtual const char* what() const throw();
};


#endif // __DFS_EXCEPTIONS_SOCKET_H__