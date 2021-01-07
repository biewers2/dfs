#ifndef __DFS_EXCEPTIONS_FS_H__
#define __DFS_EXCEPTIONS_FS_H__

#include <ios>


class FilePathException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "File path was either invalid or didn't exist.";
    }
};


class FileOpenException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Error occurred when opening file.";
    }
};


#endif // __DFS_EXCEPTIONS_FS_H__
