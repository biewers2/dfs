#ifndef __DFS_CLIENT_SOCKET_H__
#define __DFS_CLIENT_SOCKET_H__

#include <sys/socket.h>
#include <arpa/inet.h>

#include "api/Socket.h"

#define ADDRESS_LENGTH (sizeof(struct sockaddr_in))


class Client : public Socket {
private:
    int m_socketFd;
    struct sockaddr_in m_serverAddress;
    
public:
    void initSocket(const std::string& address, const int port);
    void connect();
    void send(const void* data, const size_t dataSize) override;
    ssize_t read(char* buffer, const size_t bufferSize) override;
    void close();
};


#endif // __DFS_CLIENT_SOCKET_H__