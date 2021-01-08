#include <tuple>
#include <string>

#include "api/file.h"
#include "api/Socket.h"
#include "SocketFileHashReader.h"


SocketFileHashReader::SocketFileHashReader(Socket* socket) {}


std::tuple<std::string, hashString_t, timestamp_t>
SocketFileHashReader::readHash() {
    return std::tuple<std::string, hashString_t, timestamp_t>();
}
