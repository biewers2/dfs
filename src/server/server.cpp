#include <iostream> 
#include <exception>

#include "sockio/Server.h"
#include "sockio/SocketFileSender.h"

#define OPTIONS     (1)
#define PORT        (8080)
#define FILE_NAME   ("server-file")


int main(int argc, char const* argv[]) {
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
        server->close();
        delete server;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
} 
