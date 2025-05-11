//
// Created by crazy-penguin on 5/10/25.
//

#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <string>
#include <vector>
#include <map>
#include "../utils.h"

// struct URL {
//     std::string protocol;
//     std::string host;
//     std::string file_path;
//     explicit URL(const std::string& url) {
//         // split the protocol from the rest of the URL
//         std::vector<std::string> protocol_path = utils::split(url, ':');
//         protocol = protocol_path[0];
//         // split the host name (or address) from the requested file path
//         std::vector<std::string> host_file = utils::split(protocol_path[1], '/', 1, 2);
//         host = host_file[0];
//         file_path = host_file[1];
//     }
// };

class HttpRequest {
private:
    std::string method;
    std::string path;
    std::string http_version;
    std::map<std::string, std::string> headers;
    std::string body;

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
