//
// Created by crazy-penguin on 5/9/25.
//

#ifndef CONNECTIONREFUSEDEXCEPTION_H
#define CONNECTIONREFUSEDEXCEPTION_H

#include <stdexcept>

class ConnectionRefusedException : std::runtime_error{
public:
    explicit ConnectionRefusedException(const std::string &msg);
    const char *what() const noexcept override;
};

#endif //CONNECTIONREFUSEDEXCEPTION_H
