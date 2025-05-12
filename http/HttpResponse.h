//
// Created by crazy-penguin on 5/12/25.
//

#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H

#include <string>
#include <map>

class HttpResponse {
private:
    std::string http_version;
    int status_code;
    std::string status_desc;
    std::map<std::string, std::string> headers;
    std::string body{};
public:
HttpResponse(std::string http_version, int status_code, std::string status_desc,
        const std::map<std::string, std::string> &headers, std::string body);

    std::string get_http_version() const;

    void set_http_version(const std::string &http_version);

    int get_status_code() const;

    void set_status_code(int status_code);

    std::string get_status_desc() const;

    void set_status_desc(const std::string &status_desc);

    std::map<std::string, std::string> get_headers() const;

    void set_headers(const std::map<std::string, std::string> &headers);

    std::string get_body() const;

    void set_body(const std::string &body);
};



#endif //HTTPRESPONSE_H
