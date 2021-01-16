#include <string>

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
