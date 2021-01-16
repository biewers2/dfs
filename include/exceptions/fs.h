#ifndef __DFS_EXCEPTIONS_FS_H__
#define __DFS_EXCEPTIONS_FS_H__

#include <exception>


class FileException : public std::exception {
public:
    virtual const char* what() const throw();
};


class FilePathException : public FileException {
public:
    virtual const char* what() const throw();
};


class FileOpenException : public FileException {
public:
    virtual const char* what() const throw();
};


class FileDoesNotExistException : public FileException {
public:
    virtual const char* what() const throw();
};


#endif // __DFS_EXCEPTIONS_FS_H__
