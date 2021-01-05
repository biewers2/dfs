#include <iostream> 
#include <string> 
#include <exception>

#include "sockio/Client.h"
#include "sockio/SocketFileReader.h"

#define PORT        (8080)
#define ADDRESS     ("127.0.0.1")
#define FILE_NAME   ("client-file")


int main(int argc, char const* argv[]) {
    try {
        Client* client = new Client();
        SocketFileReader* reader = new SocketFileReader(client);
        client->initSocket(ADDRESS, PORT);
        client->connect();

        std::cout << "Reading file from server..." << std::endl;
        reader->readDataIntoFile(FILE_NAME);
        std::cout << "File read from server!" << std::endl;

        delete reader;
        client->close();
        delete client;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0; 
} 
