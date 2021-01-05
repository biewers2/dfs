#ifndef __DFS_DIRECTORY_SCANNER_H__
#define __DFS_DIRECTORY_SCANNER_H__

#include <vector>
#include <string>

#include <dirent.h>

#include "Path.h"


class DirectoryScannerTest;

class DirectoryScanner {
private:
    Path m_path;
    DIR* m_directory;

public:
    DirectoryScanner();
    ~DirectoryScanner();

    void setPath(Path path);
    std::vector<std::string> getListOfFiles();
    std::vector<std::string> getListOfDirectories(bool ignoreDots = true);
    std::vector<std::string> getListOfAllContents(bool ignoreDots = true);

    friend DirectoryScannerTest;
};


#endif // __DFS_DIRECTORY_SCANNER_H__
