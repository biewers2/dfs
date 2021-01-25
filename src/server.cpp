#include <iostream> 
#include <exception>

#include "socket/Server.h"
#include "sockio/FileReceiver.h"


int main(int argc, char const* argv[]) {
    /*
     * 1. Constantly wait and read for hash (HashRecv)
     * 2. When hash received, compare hash to file on hand's hash.
     * 3. If different, look up time
     */
    try {
        Server* server = new Server();
        FileReceiver* receiver = new FileReceiver(server);
        server->initSocket(1, 8080);

        while (server->listenAndAccept()) {
            try {
                receiver->recvDataIntoFile("server-file");
            } catch(const std::exception& e) {
                std::cout << e.what() << std::endl;
            }
        }

        delete receiver;
        server->close();
        delete server;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
} 
