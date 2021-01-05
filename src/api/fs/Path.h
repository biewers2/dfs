#ifndef __DFS_FS_PATH_H__
#define __DFS_FS_PATH_H__

#include <vector>
#include <string>


class PathTest;

class Path {
private:
    void changeSingleDirectory(const std::string& stringFile);
    std::vector<std::string> parseStringPath(const std::string& stringPath);

    std::vector<std::string> m_components;
    bool m_absolute;

public:
    Path(const char* stringPath);

    bool isAbsolute();
    std::vector<std::string> getComponents();
    void changeDirectory(const std::string& stringPath);
    std::string asString();

    friend PathTest;
};


#endif // __DFS_FS_PATH_H__
