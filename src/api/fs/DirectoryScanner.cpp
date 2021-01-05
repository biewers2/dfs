#include <vector>
#include <string>

#include <dirent.h>
#include <cstring>

#include "exceptions/fs.h"
#include "Path.h"
#include "DirectoryScanner.h"


bool
isDotDirectory(const char* dir) {
    return strcmp(dir, "..") == 0 || strcmp(dir, ".") == 0;
}


DirectoryScanner::DirectoryScanner() : m_path{ Path("") }, m_directory{ nullptr } {}


DirectoryScanner::~DirectoryScanner() {
    if (m_directory) {
        closedir(m_directory);
        m_directory = nullptr;
    }
}


void DirectoryScanner::setPath(Path path) {
    DIR* directory{ opendir(path.asString().c_str()) };
    if (directory) {
        if (m_directory) {
            closedir(m_directory);
            m_directory = nullptr;
        }
        m_directory = directory;
    } else {
        throw FilePathException();
    }
    m_path = path;
}


std::vector<std::string>
DirectoryScanner::getListOfFiles() {
    std::vector<std::string> fileEntries;

    struct dirent* directoryEntry;
    while ((directoryEntry = readdir(m_directory)) != nullptr) {
        if (directoryEntry->d_type == DT_REG) {
            fileEntries.push_back(directoryEntry->d_name);
        }
    }

    return fileEntries;
}


std::vector<std::string>
DirectoryScanner::getListOfDirectories(bool ignoreDots) {
    std::vector<std::string> directoryEntries;

    struct dirent* directoryEntry;
    while ((directoryEntry = readdir(m_directory)) != nullptr) {
        if (directoryEntry->d_type == DT_DIR) {
            if (ignoreDots && isDotDirectory(directoryEntry->d_name)) {
                continue;
            }
            directoryEntries.push_back(directoryEntry->d_name);
        }
    }

    return directoryEntries;
}


std::vector<std::string>
DirectoryScanner::getListOfAllContents(bool ignoreDots) {
    std::vector<std::string> entries;

    struct dirent* directoryEntry;
    while ((directoryEntry = readdir(m_directory)) != nullptr) {
        if (ignoreDots && isDotDirectory(directoryEntry->d_name)) {
            continue;
        }
        entries.push_back(directoryEntry->d_name);
    }
    return entries;
}
