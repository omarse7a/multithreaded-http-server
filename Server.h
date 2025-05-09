//
// Created by crazy-penguin on 5/6/25.
//

#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>

#include <stdexcept>
#include "exceptions/ConnectionRefusedException.h"
#include "exceptions/ConnectionFailedException.h"

#define BUFFER_SIZE 1048576  // 1 MiB

class Server {
private:
    int port_num;
    int server_fd;
    struct sockaddr_in address{}; // internet socket structure
    socklen_t address_size;
    char* recv_buffer;

public:
    explicit Server(int port_num);
    Server* getInstance();
    void run();
    ~Server();
};



#endif //SERVER_H
