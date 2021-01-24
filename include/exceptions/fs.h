#ifndef __DFS_EXCEPTIONS_FS_H__
#define __DFS_EXCEPTIONS_FS_H__

#include <exception>


class FileException : public std::exception {
public:
    const char* what() const noexcept override;
};


class FilePathException : public FileException {
public:
    const char* what() const noexcept override;
};


class FileOpenException : public FileException {
public:
    const char* what() const noexcept override;
};


class FileDoesNotExistException : public FileException {
public:
    const char* what() const noexcept override;
};


#endif // __DFS_EXCEPTIONS_FS_H__
