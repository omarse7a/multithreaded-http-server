//
// Created by crazy-penguin on 5/9/25.
//

#ifndef CONNECTIONFAILEDEXCEPTION_H
#define CONNECTIONFAILEDEXCEPTION_H

#include <stdexcept>

class ConnectionFailedException : std::runtime_error {
public:
    explicit ConnectionFailedException(const std::string &msg);
    const char *what() const noexcept override;
};



#endif //CONNECTIONFAILEDEXCEPTION_H
