#ifndef __DFS_EXCEPTIONS_SOCKET_H__
#define __DFS_EXCEPTIONS_SOCKET_H__

#include <exception>
#include <string>
#include <cstring>
#include <cerrno>


class SocketException : public std::exception {
    const char* what() const noexcept override;
};


class SocketInitException : public SocketException {
    const char* what() const noexcept override;
};


class SocketOptionException : public SocketException {
public:
    SocketOptionException() : m_what(std::string("Socket options failed to set: ") + std::strerror(errno)) {}
    const char* what() const noexcept override;
private:
    const std::string m_what;
};


class SocketBindException : public SocketException {
    const char* what() const noexcept override;
};


class SocketListenException : public SocketException {
    const char* what() const noexcept override;
};


class SocketAcceptException : public SocketException {
    const char* what() const noexcept override;
};


class SocketAddressException : public SocketException {
    const char* what() const noexcept override;
};


class SocketConnectionException : public SocketException {
    const char* what() const noexcept override;
};


#endif // __DFS_EXCEPTIONS_SOCKET_H__