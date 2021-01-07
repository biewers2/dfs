#ifndef __DFS_SOCKIO_SOCKET_FILE_STATUS_READER_H__
#define __DFS_SOCKIO_SOCKET_FILE_STATUS_READER_H__

#include <utility>

#include "api/file.h"
#include "api/Socket.h"


class SocketFileStatusReader {
private:
    Socket* socket;

public:
    SocketFileStatusReader(Socket* socket);
    std::pair<char*, FileStatus> readStatus();
};


#endif // __DFS_SOCKIO_SOCKET_FILE_STATUS_READER_H__
