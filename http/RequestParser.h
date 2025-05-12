//
// Created by crazy-penguin on 5/10/25.
//

#ifndef REQUESTPARSER_H
#define REQUESTPARSER_H

#include <vector>
#include "HttpRequest.h"

class RequestParser {
public:
    static HttpRequest parse(const char* request, long n);
};

#endif //REQUESTPARSER_H
