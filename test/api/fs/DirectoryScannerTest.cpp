#include <string>

#include "test-util.h"
#include "fs/DirectoryScanner.h"
#include "DirectoryScannerTest.h"


void
DirectoryScannerTest::SetUp() {
    m_scanner = new DirectoryScanner();
}


void
DirectoryScannerTest::TearDown() {
    delete m_scanner;
}
