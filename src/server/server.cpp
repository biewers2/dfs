#include <iostream> 
#include <exception>
#include <exceptions/fs.h>

#include "sockio/Server.h"
#include "sockio/SocketFileReader.h"


int main(int argc, char const* argv[]) {
    try {
        Server* server = new Server();
        SocketFileReader* reader = new SocketFileReader(server);
        server->initSocket(1, 8080);

        while (server->listenAndAccept()) {
            std::cout << "Sending file..." << std::endl;
            try {
                reader->readDataIntoFile(Path("server-file"));
            } catch(const FStreamException& e) {
                std::cout << e.what() << std::endl;
            }
            std::cout << "File sent!" << std::endl;
        }

        delete reader;
        server->close();
        delete server;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
} 
