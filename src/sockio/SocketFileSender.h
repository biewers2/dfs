#ifndef __DFS_SOCKIO_SOCKET_FILE_SENDER_H__
#define __DFS_SOCKIO_SOCKET_FILE_SENDER_H__

#include <string>

#include "api/Socket.h"

class SocketFileSender {
private:
    Socket* socket;

public:
    SocketFileSender(Socket* socket);
    void sendDataFromFile(const char* fileName);

};

#endif // __DFS_SOCKIO_SOCKET_STRING_SENDER_H__