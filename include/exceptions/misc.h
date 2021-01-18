#ifndef __DFS_EXCEPTIONS_MISC_H__
#define __DFS_EXCEPTIONS_MISC_H__

#include <exception>


class EndOfIteratorException : public std::exception {
    virtual const char* what() const throw();
};


#endif // __DFS_EXCEPTIONS_MISC_H__
