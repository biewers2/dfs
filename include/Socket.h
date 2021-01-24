#ifndef __DFS_SOCKET_SOCKET__
#define __DFS_SOCKET_SOCKET__

#include <cstddef>

#include <sys/socket.h>


class Socket {
public:
    virtual void send(const void* data, size_t dataSize) = 0;
    virtual ssize_t recv(void* buffer, size_t bufferSize) = 0;
};


#endif // __DFS_SOCKET_SOCKET__