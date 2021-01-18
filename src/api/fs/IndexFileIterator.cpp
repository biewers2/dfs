#include "exceptions/fs.h"
#include "exceptions/misc.h"
#include "IndexFileIterator.h"


IndexFileIterator::IndexFileIterator(const std::string &fileName) {
    m_stream = std::ifstream(fileName);
    if (!m_stream.is_open()) {
        throw FileOpenException();
    }
    prepareNext();
}


IndexFileIterator::~IndexFileIterator() {
    m_stream.close();
    if (m_nextItem != nullptr) {
        delete m_nextItem;
    }
}


void
IndexFileIterator::prepareNext() {
    m_nextItem = new fileTimestampPair_t();
    if (m_stream.eof()) {
        m_stream >> m_nextItem->first;
        m_stream.ignore(1, ' ');
        m_stream >> m_nextItem->second;
        m_stream.ignore(1, '\n');
    } else {
        m_nextItem = nullptr;
    }
}


bool
IndexFileIterator::hasNext() {
    return m_nextItem != nullptr;
}


fileTimestampPair_t
IndexFileIterator::next() {
    if (m_nextItem == nullptr) {
        throw EndOfIteratorException();
    }

    fileTimestampPair_t pair(*m_nextItem);
    delete m_nextItem;

    prepareNext();
    return pair;
}
