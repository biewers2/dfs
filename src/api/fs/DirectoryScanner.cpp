#include <vector>
#include <string>

#include "Path.h"
#include "DirectoryScanner.h"


DirectoryScanner::DirectoryScanner() : m_path(Path("")) {}


void DirectoryScanner::setPath(Path path) {
    this->m_path = path;
}


std::vector<std::string>
DirectoryScanner::getListOfFiles() {
    return std::vector<std::string>();
}


std::vector<std::string>
DirectoryScanner::getListOfDirectories() {
    return std::vector<std::string>();
}


std::vector<std::string>
DirectoryScanner::getListOfAllContents() {
    return std::vector<std::string>();
}
