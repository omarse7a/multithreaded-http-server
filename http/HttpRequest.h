//
// Created by crazy-penguin on 5/10/25.
//

#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <string>
#include <vector>
#include <map>
#include "../utils.h"

struct URL {
    std::string protocol;
    std::string host;
    std::string file_path;
    explicit URL(const std::string& url) {
        std::vector<std::string> first_split = utils::split(url, ':');
        protocol = first_split[0];
        std::vector<std::string> second_split = utils::split(first_split[1], '/', 2);
        host = second_split[0];
        file_path = second_split[1];
    }
};

class HttpRequest {
private:
    std::string method;
    URL url;
    std::string http_version;
    std::map<std::string, std::string> headers;
    std::string body;

public:
HttpRequest(std::string method, URL url, std::string http_version,
        const std::map<std::string, std::string> &headers, std::string body);

    std::string get_method() const;

    void set_method(const std::string &method);

    URL get_url() const;

    void set_url(const URL &url);

    std::string get_http_version() const;

    void set_http_version(const std::string &http_version);

    std::map<std::string, std::string> get_headers() const;

    void set_headers(const std::map<std::string, std::string> &headers);
};



#endif //HTTPREQUEST_H
