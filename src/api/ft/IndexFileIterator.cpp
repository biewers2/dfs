#include <ios>

#include "api/fs/file.h"
#include "exceptions/fs.h"
#include "exceptions/misc.h"
#include "IndexFileIterator.h"


IndexFileIterator::IndexFileIterator(const std::string& fileName) {
    m_inputStream = std::ifstream(fileName);
    if (!m_inputStream.is_open()) {
        throw FileOpenException();
    }
    prepareNext();
}


IndexFileIterator::~IndexFileIterator() {
    m_inputStream.close();
    if (m_nextItem != nullptr) {
        delete m_nextItem;
    }
}


void
IndexFileIterator::close() {
    m_inputStream.close();
}


void
IndexFileIterator::prepareNext() {
    m_nextItem = new ftPair_t();
    if (m_inputStream >> m_nextItem->first) {
        m_inputStream.ignore(1, ' ');
        m_inputStream >> m_nextItem->second;
        m_inputStream.ignore(1, '\n');
    } else {
        m_nextItem = nullptr;
    }
}


bool
IndexFileIterator::hasNext() {
    return m_nextItem != nullptr;
}


ftPair_t
IndexFileIterator::next() {
    if (m_nextItem == nullptr) {
        throw EndOfIteratorException();
    }

    ftPair_t pair(*m_nextItem);
    delete m_nextItem;

    prepareNext();
    return pair;
}
