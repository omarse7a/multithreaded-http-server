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
    server_socket = socket(AF_INET, SOCK_STREAM, 0); // returns -1 for errors
    if(server_socket == -1) {
        throw std::runtime_error("Failed to create the socket.");
    }

    // attach socket to the port (for easy restarts)
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // bind the IP address and port to the socket
    if(bind(server_socket, reinterpret_cast<sockaddr*>(&address), address_size) == -1) {
        throw std::runtime_error("Failed to bind the IP address and the port to the socket.");
    }

}

void Server::run() const {
    // initializing a request queue of size 100
    int listen_val = listen(server_socket, 100);
    // when the queue is full -> refuse connection
    if (listen_val == -1) {
        throw ConnectionRefusedException("Request Queue is Full.");
    }
    while(true) {
        // initialize client address
        sockaddr_in client_address{};
        socklen_t client_address_size = sizeof(client_address);
        // get the first request from the pending queue
        int client_socket = accept(server_socket, reinterpret_cast<sockaddr*>(&client_address), &client_address_size);
        if (client_socket == -1) {
            throw ConnectionRefusedException("Client failed to connect to server.");
        }
        std::cout << "New client connected successfully.\n";
        // std::string request;
        memset(recv_buffer, 0, BUFFER_SIZE);
        long n_bytes = recv(client_socket, recv_buffer, BUFFER_SIZE, 0);
        if (n_bytes > 0) {
            std::cout << "Number of received bytes: " << n_bytes << std::endl;
            // request = std::string(recv_buffer, n_bytes);
        }

        // for (int i = 0; i < n_bytes; ++i) {
        //     unsigned char c = recv_buffer[i];
        //     if (std::isprint(c))
        //         std::cout << c;
        //     else if (c == '\0')
        //         std::cout << "\\0";
        //     else if (c == '\r')
        //         std::cout << "\\r";
        //     else if (c == '\n')
        //         std::cout << "\\n\n";
        //     else
        //         std::cout << "\\x" << std::hex << static_cast<int>(c);
        // }
        // std::cout << std::endl;

        HttpRequest request = RequestParser::parse(recv_buffer, n_bytes);
        std::cout << request.to_string();

        std::cout << "Client disconnected successfully.\n";
        close(client_socket);
    }
}

Server::~Server() {
    delete[] recv_buffer;
    close(server_socket);
}