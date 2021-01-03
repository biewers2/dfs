#include <vector>
#include <string>

#include "exceptions/fs.h"
#include "Path.h"

#include <iostream>

Path::Path(const char* stringPath) {
    m_components = this->parseStringPath(stringPath);
    if (!m_components.empty() && m_components.front() == "/") {
        m_absolute = true;
        m_components.erase(m_components.begin());
    }
}

#include <iostream>

void parseSingleComponent(std::vector<std::string>& pathList, std::string& component) {
    if (component == ".") {
        return;
    } else if (component == "..") {
        bool atRoot = pathList.size() == 1 && pathList.at(0) == "/";
        if (!pathList.empty() && !atRoot) {
            pathList.pop_back();
        }
    } else if (component.empty()) {
        throw FilePathParseException();
    } else {
        pathList.push_back(component);
    }
}


std::vector<std::string>
Path::parseStringPath(const std::string& stringPath) {
    std::vector<std::string> pathList;
    std::string subPath{ stringPath };
    if (stringPath.front() == '/') {
        pathList.insert(pathList.begin(), "/");
        subPath = subPath.substr(1, subPath.length());
    }
    while (!subPath.empty()) {
        std::string::size_type delimiterPosition{ subPath.find('/') };
        std::string component{ subPath };
        if (delimiterPosition == std::string::npos) { // no delimiter found.
            parseSingleComponent(pathList, component);
            break;
        }
        component = subPath.substr(0, delimiterPosition);
        parseSingleComponent(pathList, component);
        subPath = subPath.substr(delimiterPosition + 1, subPath.length());
    }
    return pathList;
}


std::vector<std::string>
Path::getComponents() {
    return this->m_components;
}


bool
Path::isAbsolute() {
    return this->m_absolute;
}


void
Path::changeDirectory(const std::string &pathString) {
    // todo
}
