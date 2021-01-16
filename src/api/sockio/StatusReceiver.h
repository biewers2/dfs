#ifndef __DFS_SOCKIO_STATUS_RECEIVER_H__
#define __DFS_SOCKIO_STATUS_RECEIVER_H__

#include <string>

#include "protocols/stp.h"
#include "Socket.h"


class StatusIOTest;

class StatusReceiver {
private:
    Socket* m_socket;

public:
    StatusReceiver(Socket* socket);
    stp::FileStatus recvStatus(std::string& fileNameHolder);

    friend StatusIOTest;
};


#endif // __DFS_SOCKIO_STATUS_RECEIVER_H__
