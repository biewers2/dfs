#include <tuple>

#include "api/file.h"
#include "api/Socket.h"
#include "SocketFileHashReader.h"


SocketFileHashReader::SocketFileHashReader(Socket* socket) {}


std::tuple<char*, hash_t, timestamp_t>
SocketFileHashReader::readHash() {
    return std::tuple<char*, hash_t, timestamp_t>();
}
