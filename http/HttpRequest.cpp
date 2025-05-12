//
// Created by crazy-penguin on 5/10/25.
//

#include "HttpRequest.h"

#include <utility>

HttpRequest::HttpRequest(std::string method, std::string path, std::string http_version,
        const std::map<std::string, std::string> &headers, std::string body)
        : method(std::move(method)),
          path(path),
          http_version(std::move(http_version)),
          headers(headers),
          body(std::move(body)) {
}

std::string HttpRequest::get_method() const {
    return method;
}

void HttpRequest::set_method(const std::string &method) {
    this->method = method;
}

std::string HttpRequest::get_path() const {
    return path;
}

void HttpRequest::set_path(const std::string &path) {
    this->path = path;
}

std::string HttpRequest::get_http_version() const {
    return http_version;
}

void HttpRequest::set_http_version(const std::string &http_version) {
    this->http_version = http_version;
}

std::map<std::string, std::string> HttpRequest::get_headers() const {
    return headers;
}

void HttpRequest::set_headers(const std::map<std::string, std::string> &headers) {
    this->headers = headers;
}

std::string HttpRequest::get_body() const {
    return body;
}
void HttpRequest::set_body(const std::string &body) {
    this->body = body;
}

std::string HttpRequest::to_string() const {
    std::string output;
    output += "Method: " + method + "\n";
    output += "HTTP Version: " + http_version + "\n";
    output += "Path: " + path + "\n";
    output += "Headers:\n";
    for (const auto& [key, value] : headers) {
        output += "  " + key + ": " + value + "\n";
    }
    output += "Body: " + body + "\n";
    return output;
}
