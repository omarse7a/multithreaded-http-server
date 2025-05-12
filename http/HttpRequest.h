//
// Created by crazy-penguin on 5/10/25.
//

#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <string>
#include <vector>
#include <map>
#include "../utils.h"

class HttpRequest {
private:
    std::string method;
    std::string path;
    std::string http_version;
    std::map<std::string, std::string> headers;
    std::string body{};

public:
HttpRequest(std::string method, std::string path, std::string http_version,
        const std::map<std::string, std::string> &headers, std::string body = "");

    std::string get_method() const;

    void set_method(const std::string &method);

    std::string get_path() const;

    void set_path(const std::string &path);

    std::string get_http_version() const;

    void set_http_version(const std::string &http_version);

    std::map<std::string, std::string> get_headers() const;

    void set_headers(const std::map<std::string, std::string> &headers);

    std::string get_body() const;

    void set_body(const std::string &body);

    std::string to_string() const;
};



#endif //HTTPREQUEST_H
