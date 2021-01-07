#include <iostream> 
#include <exception>

#include "exceptions/fs.h"
#include "sockio/Client.h"
#include "sockio/SocketFileSender.h"


int main(int argc, char const* argv[]) {
    try {
        Client* client = new Client();
        SocketFileSender* sender = new SocketFileSender(client);
        client->initSocket("127.0.0.1", 8080);
        client->connect();

        try {
            sender->sendDataFromFile(Path("client-file"));
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }

        delete sender;
        client->close();
        delete client;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0; 
} 
