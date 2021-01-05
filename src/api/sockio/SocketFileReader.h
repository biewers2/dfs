#ifndef __DFS_SOCKIO_SOCKET_FILE_READER_H__
#define __DFS_SOCKIO_SOCKET_FILE_READER_H__

#include <string>

#include "fs/Path.h"
#include "api/Socket.h"


class SocketFileReaderTest;

class SocketFileReader {
private:
    Socket* socket;

public:
    SocketFileReader(Socket* socket);
    void readDataIntoFile(Path path);

    friend SocketFileReaderTest;
};


#endif // __DFS_SOCKIO_SOCKET_FILE_READER_H__
