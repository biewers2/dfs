#include "STPBuilder.h"


void
STPBuilder::buildEmpty(const stp::header_t* header, stp::content_t* dataHolder) {
    dataHolder->fileName = new char[header->fileNameSize];
}


void
STPBuilder::build(const std::string& fileName, const stp::FileStatus status, stp::header_t* headerHolder, stp::content_t* dataHolder) {
    headerHolder->fileNameSize = fileName.size() + 1;

    dataHolder->fileName = new char[headerHolder->fileNameSize];
    fileName.copy(dataHolder->fileName, fileName.size());
    dataHolder->fileName[fileName.size()] = '\0';

    dataHolder->status = status;
}


void
STPBuilder::destroy(stp::content_t* data) {
    delete data->fileName;
}
