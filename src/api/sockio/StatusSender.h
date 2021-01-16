#ifndef __DFS_SOCKIO_STATUS_SENDER_H__
#define __DFS_SOCKIO_STATUS_SENDER_H__

#include <string>
#include "protocols/stp.h"
#include "Socket.h"


class StatusIOTest;

class StatusSender {
private:
    Socket* m_socket;

public:
    StatusSender(Socket* socket);
    void sendStatus(const std::string& fileName, const stp::FileStatus status);

    friend StatusIOTest;
};


#endif // __DFS_SOCKIO_STATUS_SENDER_H__
