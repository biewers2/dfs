#ifndef __DFS_CLIENT_SOCKET_H__
#define __DFS_CLIENT_SOCKET_H__

#include <sys/socket.h>
#include <arpa/inet.h>

#include "api/Socket.h"

class Client : public Socket {
private:
    int socketFd;
    struct sockaddr_in serverAddress;
    
public:
    void initSocket(const char* address, const int port);
    void connect();
    void send(const void* data, const size_t dataSize) override;
    ssize_t read(char* buffer, const size_t bufferSize) override;
};

#endif // __DFS_CLIENT_SOCKET_H__