#ifndef __DFS_DIRECTORY_SCANNER_H__
#define __DFS_DIRECTORY_SCANNER_H__

#include <vector>
#include <string>

#include <dirent.h>


class DirectoryScannerTest;

class DirectoryScanner {
private:
    DIR* m_directory;

public:
    DirectoryScanner();
    ~DirectoryScanner();

    void setDirectory(const char* dirName);
    std::vector<std::string> getListOfFiles();
    std::vector<std::string> getListOfDirectories(bool ignoreDots = true);
    std::vector<std::string> getListOfAllContents(bool ignoreDots = true);

    friend DirectoryScannerTest;
};


#endif // __DFS_DIRECTORY_SCANNER_H__
