#ifndef __DFS_TESTING_UTIL_H__
#define __DFS_TESTING_UTIL_H__

#include <vector>
#include <string>
#include <functional>

#include "socket/Client.h"
#include "socket/Server.h"

#define TEST_SERVER_CLIENT(sr, cr) ({ std::function<void(void)> serverRoutine, clientRoutine;            \
                                      serverRoutine = sr; clientRoutine = cr;                            \
                                      testSocketsWith(m_server, serverRoutine, m_client, clientRoutine); })


bool vectorContainsString(const std::vector<std::string>& vec, const std::string& str);

void createRandomFile(const std::string& fileName, size_t sizeInBytes);

void deleteFile(const std::string& fileName);

void touchFile(const std::string& fileName);

bool filesAreEqual(const std::string& fileName1, const std::string& fileName2);

void testSocketsWith(Server* server, std::function<void(void)>& serverRoutine,
                     Client* client, std::function<void(void)>& clientRoutine);


#endif // __DFS_TESTING_UTIL_H__
