#include <iostream> 
#include <cstdlib> 
#include <string> 
#include <exception>

#include "Server.h"
#include "../sockio/SocketFileSender.h"

#define OPTIONS     (1)
#define PORT        (8080)
#define FILE_NAME   ("server-file")

int main(int argc, char const* argv[]) {
    std::cout << argv[0]
              << " v" << DFS_VERSION_MAJOR << "." << DFS_VERSION_MINOR
              << "\nServer"
              << std::endl;
    try {
        Server* server = new Server();
        SocketFileSender* sender = new SocketFileSender(server);
        server->initSocket(OPTIONS, PORT);

        while (server->listenAndAccept()) {
            std::cout << "Sending file..." << std::endl;
            sender->sendDataFromFile(FILE_NAME);
            std::cout << "File sent!" << std::endl;
        }

        delete sender;
        delete server;
    } catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
} 
