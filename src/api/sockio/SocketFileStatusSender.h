#ifndef __DFS_SOCKIO_SOCKET_FILE_STATUS_SENDER_H__
#define __DFS_SOCKIO_SOCKET_FILE_STATUS_SENDER_H__

#include <string>

#include "api/file.h"
#include "api/Socket.h"


class SocketFileStatusSender {
private:
    Socket* socket;

public:
    SocketFileStatusSender(Socket* socket);
    void sendStatus(const std::string& fileName, hash_t& value);
};


#endif // __DFS_SOCKIO_SOCKET_FILE_STATUS_SENDER_H__
