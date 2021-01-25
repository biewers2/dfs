#include <string>
#include <cstdio>

#include <sys/stat.h>
#include <unistd.h>

#include <cryptopp/sha.h>
#include <cryptopp/crc.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/channels.h>

#include "exceptions/fs.h"
#include "api/fs/file.h"

namespace file {

hashString_t
hashContents(const std::string& fileName) {
    using namespace CryptoPP;

    if (!fileExists(fileName)) {
        throw FileDoesNotExistException();
    }

    std::string crcOutput, shaOutput;
    CRC32 crcHash;
    SHA256 shaHash;

    HashFilter crcFilter(crcHash, new HexEncoder(new StringSink(crcOutput)));
    HashFilter shaFilter(shaHash, new HexEncoder(new StringSink(shaOutput)));

    ChannelSwitch channelSwitch;
    channelSwitch.AddDefaultRoute(crcFilter);
    channelSwitch.AddDefaultRoute(shaFilter);

    // Does hashing of file during object construction.
    FileSource(fileName.c_str(), true /*pumpAll*/, new Redirector(channelSwitch));

    return shaOutput;
}


timestamp_t getLastModified(const std::string& fileName) {
    struct stat fileStat{};
    stat(fileName.c_str(), &fileStat);
#ifdef __APPLE__
    return fileStat.st_mtimespec;
#else
    stat(fileName.c_str(), &fileStat);
    return fileStat.st_atim;
#endif
}

size_t
getSizeOfFile(FILE* fd) {
    long currPosition{ ftell(fd) };
    fseek(fd, 0L, SEEK_END);

    long size{ ftell(fd) };
    fseek(fd, currPosition, SEEK_SET);

    return size;
}


size_t
getSizeOfFile(const std::string& fileName) {
    FILE* fd{ fopen(fileName.c_str(), "r") };
    size_t size{ getSizeOfFile(fd) };
    fclose(fd);
    return size;
}


bool
fileExists(const std::string& fileName) {
    return (access(fileName.c_str(), F_OK) != -1);
}

}
