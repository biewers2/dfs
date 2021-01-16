#ifndef __DFS_SOCKIO_FILE_RECEIVER_H__
#define __DFS_SOCKIO_FILE_RECEIVER_H__

#include <string>

#include "Socket.h"

#define BUFFER_SIZE (1024)


class FileIOTest;

class FileReceiver {
private:
    Socket* m_socket;

public:
    FileReceiver(Socket* socket);
    void recvDataIntoFile(const std::string& fileName);

    friend FileIOTest;
};


#endif // __DFS_SOCKIO_FILE_RECEIVER_H__
