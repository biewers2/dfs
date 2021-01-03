#ifndef __DFS_DIRECTORY_SCANNER_H__
#define __DFS_DIRECTORY_SCANNER_H__

#include <vector>
#include <string>

#include "Path.h"


class DirectoryScannerTest;

class DirectoryScanner {
private:
    Path m_path;

public:
    DirectoryScanner();

    void setPath(Path path);
    std::vector<std::string> getListOfFiles();
    std::vector<std::string> getListOfDirectories();
    std::vector<std::string> getListOfAllContents();

    friend DirectoryScannerTest;
};


#endif // __DFS_DIRECTORY_SCANNER_H__
