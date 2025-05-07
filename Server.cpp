//
// Created by crazy-penguin on 5/6/25.
//

#include "Server.h"

Server::Server(const int port_num): port_num(port_num) {
    // configure server address
    address.sin_addr.s_addr = INADDR_ANY;   // listen on all IP addresses of the machine
    address.sin_family = AF_INET;
    address.sin_port = htons(port_num); // transforms port_num to network byte order (big-endian)

    address_size = sizeof(address);

    recv_buffer = new char[BUFFER_SIZE];    // initialize a buffer of size 1 MiB

    // create a TCP socket with IPv4
    server_fd = socket(AF_INET, SOCK_STREAM, 0); // returns -1 for errors
    if(server_fd == -1) {
        throw std::runtime_error("Socket Creation Failed.");
    }

    // Attach socket to the port (for easy restarts)
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // bind the IP address and port to the socket
    if(bind(server_fd, reinterpret_cast<sockaddr*>(&address), address_size) == -1) {
        throw std::runtime_error("Binding Failed.");
    }
}

void Server::run() {
    // initializing a request queue of size 10
    int listen_val = listen(server_fd, 10);
    // when the queue is full -> refuse connection
    if (listen_val == -1) {
        throw std::runtime_error("Request Queue is Full.");
    }
    while(true) {
        // initialize client address
        sockaddr_in client_address{};
        socklen_t client_address_size = sizeof(client_address);
        // get the first request from the pending queue
        int client_fd = accept(server_fd, reinterpret_cast<sockaddr*>(&client_address), &client_address_size);
        if (client_fd == -1) {
            throw std::runtime_error("Client Connection Failed.");
        }
        std::cout << "New client connected successfully.\n";
        long n_bytes = recv(client_fd, &recv_buffer, BUFFER_SIZE, 0);
        if (n_bytes > 0) {
            std::cout << "Number of received bytes: " << n_bytes << std::endl;
            std::cout << "Message from client: " << recv_buffer;
        }
        std::cout << "Client disconnected successfully.\n";
        close(client_fd);
    }
}

Server::~Server() {
    close(server_fd);
}