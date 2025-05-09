//
// Created by crazy-penguin on 5/9/25.
//

#include "ConnectionRefusedException.h"

ConnectionRefusedException::ConnectionRefusedException(const std::string &msg) : runtime_error(msg){}

const char * ConnectionRefusedException::what() const noexcept {
    return runtime_error::what();
}
