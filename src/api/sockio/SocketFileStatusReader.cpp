#include <utility>
#include <string>

#include "api/file.h"
#include "api/Socket.h"
#include "SocketFileStatusReader.h"


SocketFileStatusReader::SocketFileStatusReader(Socket* socket) {}


std::pair<std::string, FileStatus>
SocketFileStatusReader::readStatus() {
    return std::pair<std::string, FileStatus>();
}
