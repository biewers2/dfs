#include <string>

#include "util/STPBuilder.h"
#include "protocols/stp.h"
#include "Socket.h"
#include "StatusSender.h"


StatusSender::StatusSender(Socket* socket) {
    m_socket = socket;
}


void
StatusSender::sendStatus(const std::string& fileName, const stp::FileStatus status) {
    STPBuilder builder;
    stp::header_t header{};
    stp::content_t content{};
    builder.build(fileName, status, &header, &content);

    this->m_socket->send(&header, stp::HEADER_SIZE);
    this->m_socket->send(content.fileName, header.fileNameSize);
    this->m_socket->send(&content.status, sizeof(stp::FileStatus));

    builder.destroy(&content);
}
