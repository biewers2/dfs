#include "fs/DirectoryScanner.h"
#include "DirectoryScannerTest.h"


void
DirectoryScannerTest::SetUp() {
    this->m_scanner = new DirectoryScanner();
}


void
DirectoryScannerTest::TearDown() {
    delete this->m_scanner;
}


bool
DirectoryScannerTest::listContainsString(const std::vector<std::string>& list, const std::string& str) {
    for (const auto& element : list) {
        if (element == str) {
            return true;
        }
    }
    return false;
}
