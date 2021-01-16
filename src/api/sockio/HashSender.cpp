#include <string>

#include "util/HTPBuilder.h"
#include "protocols/htp.h"
#include "Socket.h"
#include "HashSender.h"

#define BUFFER_SIZE (1024)


HashSender::HashSender(Socket* socket) {
    m_socket = socket;
}


void
HashSender::sendHash(const std::string& fileName) {
    HTPBuilder builder;
    htp::header_t header;
    htp::content_t content;
    builder.build(fileName, &header, &content);

    this->m_socket->send(&header, htp::HEADER_SIZE);
    this->m_socket->send(content.fileName, header.fileNameSize);
    this->m_socket->send(content.hash, header.hashSize);

    builder.destroy(&content);
}
