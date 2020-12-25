#ifndef __DFS_DIRECTORY_SCANNER_H__
#define __DFS_DIRECTORY_SCANNER_H__

#include <vector>
#include <string>


class DirectoryScanner {
private:
    std::vector<std::string>* path;
    std::vector<std::string> parseStringPath(const std::string& stringPath);
    void changeSingleDirectory(const std::string& dirName);

public:
    DirectoryScanner(const std::string& dirStringPath);
    ~DirectoryScanner();
    void changeDirectory(const std::string& stringPath);
    std::vector<std::string> getListOfFiles();
    std::vector<std::string> getListOfDirectories();

};


#endif // __DFS_DIRECTORY_SCANNER_H__
