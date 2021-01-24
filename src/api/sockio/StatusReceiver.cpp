
#include "util/STPBuilder.h"
#include "protocols/stp.h"
#include "Socket.h"
#include "StatusReceiver.h"


StatusReceiver::StatusReceiver(Socket* socket) {
    m_socket = socket;
}


stp::FileStatus
StatusReceiver::recvStatus(std::string& fileNameHolder) {
    STPBuilder builder;
    stp::header_t header{};
    this->m_socket->recv(&header, stp::HEADER_SIZE);

    stp::content_t content{};
    builder.buildEmpty(&header, &content);
    this->m_socket->recv(content.fileName, header.fileNameSize);
    this->m_socket->recv(&content.status, sizeof(stp::FileStatus));

    fileNameHolder = content.fileName;
    stp::FileStatus status = content.status;
    builder.destroy(&content);
    return status;
}