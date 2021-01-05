#ifndef __DFS_SOCKIO_SOCKET_FILE_SENDER_H__
#define __DFS_SOCKIO_SOCKET_FILE_SENDER_H__

#include <string>

#include "fs/Path.h"
#include "api/Socket.h"


class SocketFileSender {
private:
    Socket* socket;

public:
    SocketFileSender(Socket* socket);
    void sendDataFromFile(Path path);

};


#endif // __DFS_SOCKIO_SOCKET_STRING_SENDER_H__