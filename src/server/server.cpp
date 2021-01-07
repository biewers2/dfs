#include <iostream> 
#include <exception>

#include "sockio/Server.h"
#include "sockio/SocketFileReader.h"


int main(int argc, char const* argv[]) {
    try {
        Server* server = new Server();
        SocketFileReader* reader = new SocketFileReader(server);
        server->initSocket(1, 8080);

        while (server->listenAndAccept()) {
            try {
                reader->readDataIntoFile("server-file");
            } catch(const std::exception& e) {
                std::cout << e.what() << std::endl;
            }
        }

        delete reader;
        server->close();
        delete server;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
} 
