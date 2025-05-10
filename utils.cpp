//
// Created by crazy-penguin on 5/10/25.
//

#include "utils.h"

namespace utils {
    std::vector<std::string> split(const std::string& s, const char& delimiter, int skips)
    {
        std::vector<std::string> splitted;
        int k = 0;
        for (int i = 0; i < s.size(); ++i) {
            if(s[i] == delimiter) {
                if (skips > 0) {
                    k = i+1;
                    --skips;
                    continue;
                }
                splitted.emplace_back(s.substr(k, i-1));
                k = i+1;
            }
        }
        return splitted;
    }
}