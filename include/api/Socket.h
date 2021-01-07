#ifndef __DFS_API_SOCKET__
#define __DFS_API_SOCKET__

#include <cstddef>

#include <sys/socket.h>


class Socket {
public:
    virtual void send(const void* data, const size_t dataSize) = 0;
    virtual ssize_t read(char* buffer, const size_t bufferSize) = 0;
};


#endif // __DFS_API_SOCKET__