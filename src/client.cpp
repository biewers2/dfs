#include <iostream> 
#include <exception>

#include "exceptions/fs.h"
#include "socket/Client.h"
#include "sockio/FileSender.h"


int main(int argc, char const* argv[]) {
    try {
        Client client;
        FileSender sender(&client);
        client.initSocket("127.0.0.1", 8080);
        client.connect();

        try {
            sender.sendDataFromFile("client-file");
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0; 
} 
