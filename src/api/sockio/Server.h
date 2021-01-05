#ifndef __DFS_SERVER_SOCKET_H__
#define __DFS_SERVER_SOCKET_H__

#include <iostream>

#include <sys/socket.h>
#include <netinet/in.h>

#include "api/Socket.h"

#define ADDRESS_LENGTH (sizeof(struct sockaddr_in))


class Server : public Socket {
private:
    int m_socketFd;
    int m_clientSocketFd;
    struct sockaddr_in m_address;
    
public:
    void initSocket(const int options, const int port);
    bool listenAndAccept();
    void send(const void* data, const size_t dataSize) override;
    ssize_t read(char* buffer , const size_t bufferSize) override;
    void close();
};


#endif // __DFS_SERVER_SOCKET_H__