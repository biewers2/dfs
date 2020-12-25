#include <vector>
#include <string>

#include "DirectoryScanner.h"


std::vector<std::string>
DirectoryScanner::parseStringPath(const std::string& stringPath) {
}


void
DirectoryScanner::changeSingleDirectory(const std::string& dirName) {
    if (dirName == ".." && this->path->size() > 0) {
        this->path->pop_back();
    } else {
        this->path->push_back(dirName);
    }
}


DirectoryScanner::DirectoryScanner(const std::string& dirStringPath) {
    this->path = new std::vector<std::string>();
    for (std::string& fileName : this->parseStringPath(dirStringPath)) {
        this->changeSingleDirectory(fileName);
    }
}


DirectoryScanner::~DirectoryScanner() {
    delete this->path;
}


void
DirectoryScanner::changeDirectory(const std::string& stringPath) {
    for (std::string& fileName : this->parseStringPath(stringPath)) {
        this->changeSingleDirectory(fileName);
    }
}