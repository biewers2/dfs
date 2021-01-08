#ifndef __DFS_SOCKIO_SOCKET_FILE_HASH_READER_H__
#define __DFS_SOCKIO_SOCKET_FILE_HASH_READER_H__

#include <tuple>
#include <string>

#include "api/file.h"
#include "api/Socket.h"


class SocketFileHashReader {
private:
    Socket* socket;

public:
    SocketFileHashReader(Socket* socket);
    std::tuple<std::string, hashString_t, timestamp_t> readHash();
};


#endif // __DFS_SOCKIO_SOCKET_FILE_HASH_READER_H__
