#ifndef __DFS_SOCKIO_SOCKET_FILE_READER_H__
#define __DFS_SOCKIO_SOCKET_FILE_READER_H__

#include <string>

#include "api/Socket.h"

class SocketFileReader {
private:
    Socket* socket;

public:
    SocketFileReader(Socket* socket);
    void readDataIntoFile(const char* fileName);

};

#endif // __DFS_SOCKIO_SOCKET_FILE_READER_H__
