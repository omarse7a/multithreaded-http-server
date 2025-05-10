//
// Created by crazy-penguin on 5/10/25.
//

#include "HttpRequest.h"

#include <utility>

HttpRequest::HttpRequest(std::string method, URL url, std::string http_version,
        const std::map<std::string, std::string> &headers, std::string body)
        : method(std::move(method)),
          url(std::move(url)),
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

URL HttpRequest::get_url() const {
    return url;
}

void HttpRequest::set_url(const URL &url) {
    this->url = url;
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