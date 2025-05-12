//
// Created by crazy-penguin on 5/12/25.
//

#include "HttpResponse.h"

#include <utility>

HttpResponse::HttpResponse(std::string http_version, const int status_code, std::string status_desc,
        const std::map<std::string, std::string> &headers, std::string body)
        : http_version(std::move(http_version)),
          status_code(status_code),
          status_desc(std::move(status_desc)),
          headers(headers),
          body(std::move(body)) {}

std::string HttpResponse::get_http_version() const {
    return http_version;
}

void HttpResponse::set_http_version(const std::string &http_version) {
    this->http_version = http_version;
}

int HttpResponse::get_status_code() const {
    return status_code;
}

void HttpResponse::set_status_code(const int status_code) {
    this->status_code = status_code;
}

std::string HttpResponse::get_status_desc() const {
    return status_desc;
}

void HttpResponse::set_status_desc(const std::string &status_desc) {
    this->status_desc = status_desc;
}

std::map<std::string, std::string> HttpResponse::get_headers() const {
    return headers;
}

void HttpResponse::set_headers(const std::map<std::string, std::string> &headers) {
    this->headers = headers;
}

std::string HttpResponse::get_body() const {
    return body;
}

void HttpResponse::set_body(const std::string &body) {
    this->body = body;
}