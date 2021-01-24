#ifndef __DFS_SOCKIO_FILE_SENDER_H__
#define __DFS_SOCKIO_FILE_SENDER_H__

#include <string>

#include "Socket.h"

#define BUFFER_SIZE (1024)


class FileIOTest;

class FileSender {
private:
    Socket* m_socket;

public:
    explicit FileSender(Socket* socket);
    void sendDataFromFile(const std::string& fileName);

    friend FileIOTest;
};


#endif // __DFS_SOCKIO_FILE_SENDER_H__
