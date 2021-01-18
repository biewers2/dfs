#include "exceptions/misc.h"


const char*
EndOfIteratorException::what() const throw() {
    return "Tried to access next element when none remain.";
}
