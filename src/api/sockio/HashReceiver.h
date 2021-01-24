#ifndef __DFS_SOCKIO_HASH_RECEIVER_H__
#define __DFS_SOCKIO_HASH_RECEIVER_H__

#include <string>
#include <api/fs/file.h>

#include "Socket.h"
#include "protocols/htp.h"


class HashIOTest;

class HashReceiver {
private:
    Socket* m_socket;

public:
    explicit HashReceiver(Socket* socket);
    file::hashString_t recvHash(std::string& fileNameHolder);

    friend HashIOTest;
};


#endif // __DFS_SOCKIO_HASH_RECEIVER_H__
