#ifndef __DFS_UTIL_OVERLAP_H__
#define __DFS_UTIL_OVERLAP_H__

#include <iostream>
#include <sys/socket.h>

// Prevents function naming conflicts between sys/socket and this project.

class csock {
public:
    static int connect(int sockfd, const struct sockaddr* addr, socklen_t addrlen);
    static ssize_t send(int socket, const void* buffer, size_t length, int flags);
    static ssize_t read(int fd, void* buf, size_t count);
};

int csock::connect(int sockfd, const struct sockaddr* addr, socklen_t addrlen) {
    return ::connect(sockfd, addr, addrlen);
}

ssize_t csock::send(int socket, const void* buffer, size_t length, int flags) {
    return ::send(socket, buffer, length, flags);
}

ssize_t csock::read(int fd, void* buf, size_t count) {
    return ::read(fd, buf, count);
}

#endif // __DFS_UTIL_OVERLAP_H__