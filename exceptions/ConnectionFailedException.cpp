//
// Created by crazy-penguin on 5/9/25.
//

#include "ConnectionFailedException.h"

ConnectionFailedException::ConnectionFailedException(const std::string &msg) : runtime_error(msg) {}

const char * ConnectionFailedException::what() const noexcept {
    return runtime_error::what();
}
