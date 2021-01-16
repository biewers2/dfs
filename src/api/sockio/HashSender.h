#ifndef __DFS_SOCKIO_HASH_SENDER_H__
#define __DFS_SOCKIO_HASH_SENDER_H__

#include <string>
#include "Socket.h"


class HashIOTest;

class HashSender {
private:
    Socket* m_socket;

public:
    HashSender(Socket* socket);
    void sendHash(const std::string& fileName);

    friend HashIOTest;
};


#endif // __DFS_SOCKIO_HASH_SENDER_H__
