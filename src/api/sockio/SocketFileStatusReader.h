#ifndef __DFS_SOCKIO_SOCKET_FILE_STATUS_READER_H__
#define __DFS_SOCKIO_SOCKET_FILE_STATUS_READER_H__

#include <utility>
#include <string>

#include "api/file.h"
#include "api/Socket.h"


class SocketFileStatusReader {
private:
    Socket* socket;

public:
    SocketFileStatusReader(Socket* socket);
    std::pair<std::string, FileStatus> readStatus();
};


#endif // __DFS_SOCKIO_SOCKET_FILE_STATUS_READER_H__
