#include "exceptions/fs.h"


const char*
FileException::what() const noexcept {
    return "An error occurred relating to a file operation.";
}


const char*
FilePathException::what() const noexcept {
    return "File path was either invalid or didn't exist.";
}


const char*
FileOpenException::what() const noexcept {
    return "Error occurred when opening file.";
}


const char*
FileDoesNotExistException::what() const noexcept {
    return "File does not exist.";
}
