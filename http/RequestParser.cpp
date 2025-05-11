//
// Created by crazy-penguin on 5/10/25.
//

#include "RequestParser.h"

HttpRequest RequestParser::parse(const char *request, long n) {
    std::vector<std::string> info_body = utils::split(request, "\r\n\r\n");
    std::vector<std::string> request_info_lines = utils::split(info_body[0], "\r\n");
    std::vector<std::string> request_line = utils::split(request_info_lines[0], ' ');

    std::map<std::string, std::string> headers;
    for (int i = 1; i < request_info_lines.size(); ++i) {
        std::vector<std::string> key_val = utils::split(request_info_lines[i], ':', 1);
        headers[key_val[0]] = utils::trim(key_val[1]);
    }
    return HttpRequest(request_line[0], request_line[1], request_line[2], headers, info_body[1]);
}
