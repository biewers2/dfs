#ifndef __DFS_SERVER_SOCKET_H__
#define __DFS_SERVER_SOCKET_H__

#include <iostream>

//#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "api/Socket.h"

class Server : public Socket {
private:
    socklen_t addressLength{ sizeof(struct sockaddr_in) };
    int socketFd;
    int clientSocketFd;
    struct sockaddr_in address;
    
public:
    void initSocket(const int options, const int port);
    bool listenAndAccept();
    void send(const void* data, const size_t dataSize) override;
    ssize_t read(char* buffer , const size_t bufferSize) override;
};

#endif // __DFS_SERVER_SOCKET_H__