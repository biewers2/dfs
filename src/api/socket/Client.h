#ifndef __DFS_CLIENT_SOCKET_H__
#define __DFS_CLIENT_SOCKET_H__

#include <sys/socket.h>
#include <arpa/inet.h>

#include "Socket.h"

#define ADDRESS_LENGTH (sizeof(struct sockaddr_in))


class Client : public Socket {
private:
    int m_socketFd{};
    struct sockaddr_in m_serverAddress{};
    
public:
    virtual ~Client();

    void initSocket(const std::string& address, int port);
    void connect();
    void send(const void* data, size_t dataSize) override;
    ssize_t recv(void* buffer, size_t bufferSize) override;
    void close();
};


#endif // __DFS_CLIENT_SOCKET_H__