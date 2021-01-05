#ifndef __DFS_EXCEPTIONS_FS_H__
#define __DFS_EXCEPTIONS_FS_H__


class FilePathParseException : public std::exception {
    virtual const char* what() const throw() {
        return "Invalid file path was parsed.";
    }
};


class FilePathException : public std::exception {
    virtual const char* what() const throw() {
        return "File path was either invalid or didn't exist.";
    }
};


#endif // __DFS_EXCEPTIONS_FS_H__
