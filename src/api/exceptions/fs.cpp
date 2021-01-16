#include "exceptions/fs.h"


const char*
FileException::what() const throw() {
    return "An error occurred relating to a file operation.";
}


const char*
FilePathException::what() const throw() {
    return "File path was either invalid or didn't exist.";
}


const char*
FileOpenException::what() const throw() {
    return "Error occurred when opening file.";
}


const char*
FileDoesNotExistException::what() const throw() {
    return "File does not exist.";
}
