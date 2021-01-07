#include <utility>

#include "api/file.h"
#include "api/Socket.h"
#include "SocketFileStatusReader.h"


SocketFileStatusReader::SocketFileStatusReader(Socket* socket) {}


std::pair<char*, FileStatus>
SocketFileStatusReader::readStatus() {
    return std::pair<char*, FileStatus>();
}
