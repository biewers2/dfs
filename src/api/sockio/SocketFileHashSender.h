#ifndef __DFS_SOCKIO_SOCKET_FILE_HASH_SENDER_H__
#define __DFS_SOCKIO_SOCKET_FILE_HASH_SENDER_H__

#include <string>

#include "api/Socket.h"


class SocketFileHashSender {
private:
    Socket* socket;

public:
    SocketFileHashSender(Socket* socket);
    void sendHash(const std::string& fileName);
};


#endif // __DFS_SOCKIO_SOCKET_FILE_HASH_SENDER_H__
