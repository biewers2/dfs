#include "util/HTPBuilder.h"
#include "protocols/htp.h"
#include "Socket.h"
#include "HashReceiver.h"


HashReceiver::HashReceiver(Socket* socket) {
    m_socket = socket;
}


hashString_t HashReceiver::recvHash(std::string& fileNameHolder) {
    HTPBuilder builder;
    htp::header_t header;
    this->m_socket->recv(&header, htp::HEADER_SIZE);

    htp::content_t content;
    builder.buildEmpty(&header, &content);
    this->m_socket->recv(content.fileName, header.fileNameSize);
    this->m_socket->recv(content.hash, header.hashSize);

    fileNameHolder = content.fileName;
    hashString_t hashValue{ content.hash };
    builder.destroy(&content);
    return hashValue;
}
