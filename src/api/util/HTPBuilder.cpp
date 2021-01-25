#include "api/fs/file.h"
#include "HTPBuilder.h"


void
HTPBuilder::buildEmpty(const htp::header_t* header, htp::content_t* dataHolder) {
    dataHolder->fileName = new char[header->fileNameSize];
    dataHolder->hash = new char[header->hashSize];
}


void
HTPBuilder::build(const std::string& fileName, htp::header_t* headerHolder, htp::content_t* dataHolder) {
    file::hashString_t hashValue{ file::hashContents(fileName) };
    headerHolder->fileNameSize = fileName.size() + 1;
    headerHolder->hashSize = hashValue.size() + 1;

    dataHolder->fileName = new char[headerHolder->fileNameSize];
    fileName.copy(dataHolder->fileName, fileName.size());
    dataHolder->fileName[fileName.size()] = '\0';

    dataHolder->hash = new char[headerHolder->hashSize];
    hashValue.copy(dataHolder->hash, hashValue.size());
    dataHolder->hash[hashValue.size()] = '\0';
}


void
HTPBuilder::destroy(htp::content_t* data) {
    delete data->fileName;
    delete data->hash;
}
