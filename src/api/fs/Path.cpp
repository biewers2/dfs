#include <vector>
#include <string>

#include "exceptions/fs.h"
#include "Path.h"


Path::Path(const char* stringPath) {
    m_absolute = false;
    this->changeDirectory(stringPath);
}


void
Path::changeSingleDirectory(const std::string& stringFile) {
    if (stringFile == ".") {
        return;
    } else if (stringFile == "..") {
        if (!m_components.empty()) {
            m_components.pop_back();
        }
    } else if (stringFile.empty()) {
        throw FilePathException();
    } else {
        m_components.push_back(stringFile);
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
            pathList.push_back(component);
            break;
        }

        component = subPath.substr(0, delimiterPosition);
        if (component.empty()) {
            throw FilePathParseException();
        }
        pathList.push_back(component);
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
Path::changeDirectory(const std::string &stringPath) {
    std::vector<std::string> components = parseStringPath(stringPath);
    if (!components.empty() && components.front() == "/") {
        m_absolute = true;
        components.erase(components.begin());
    }
    for (const std::string& component : components) {
        changeSingleDirectory(component);
    }
}


std::string
Path::asString() {
    std::string stringPath{ "" };
    if (m_absolute) {
        stringPath += '/';
    }
    for (const std::string& component : m_components) {
        stringPath += component + '/';
    }
    return stringPath;
}