#include <string>
#include "FTQueue.h"


FTQueue::FTQueue() {
    m_queue = new ftQueue_t();
}


FTQueue::~FTQueue() {
    delete m_queue;
}


size_t
FTQueue::size() {
    return m_queue->size();
}


ftIterator_t
FTQueue::find(const std::string& fileNameEntry) {
    for (ftIterator_t it{ m_queue->begin() }; it != m_queue->end(); ++it) {
        if (it->first == fileNameEntry) {
            return it;
        }
    }
    return end();
}


bool
FTQueue::contains(const std::string& fileNameEntry) {
    return find(fileNameEntry) != end();
}


void
FTQueue::enqueue(const ftPair_t& entry) {
    m_queue->insert(m_queue->begin(), entry);
}


ftPair_t
FTQueue::dequeue() {
    ftPair_t backEntry{ m_queue->back() };
    m_queue->pop_back();
    return backEntry;
}


void
FTQueue::set(const std::string& fileName, const timestamp_t& timestamp) {
    const ftIterator_t position{ find(fileName) };
    if (position != end()) {
        set(position, timestamp);
    }
}


void
FTQueue::set(const ftIterator_t& position, const timestamp_t& timestamp) {
    position->second = timestamp;
}


void
FTQueue::insert(const ftIterator_t& position, const ftPair_t& entry) {
    m_queue->insert(position, entry);
}


ftPair_t
FTQueue::erase(const ftIterator_t &position) {
    m_queue->erase(position);
}


ftIterator_t
FTQueue::begin() {
    return m_queue->begin();
}


ftIterator_t
FTQueue::end() {
    return m_queue->end();
}