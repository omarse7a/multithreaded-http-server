//
// Created by crazy-penguin on 5/10/25.
//

#include "utils.h"

namespace utils {
    std::vector<std::string> split(const std::string &s, const char &delimiter, int splits, int skips) {
        std::vector<std::string> tokens;

        int k = 0;
        int i;
        for (i = 0; i < s.size(); ++i) {
            if (splits == 0) {
                break;
            }
            if(s[i] == delimiter) {
                if (skips > 0) {
                    k = i+1;
                    --skips;
                    continue;
                }
                tokens.emplace_back(s.substr(k, i-k));
                k = i+1;
                --splits;
            }
        }
        tokens.emplace_back(s.substr(k, s.size()-k+1)); // include the last token
        return tokens;
    }
    std::vector<std::string> split(std::string s, const std::string& delimiter) {
        std::vector<std::string> tokens;
        size_t pos = 0;
        while ((pos = s.find(delimiter)) != std::string::npos) {
            std::string token = s.substr(0, pos);
            tokens.push_back(token);
            s.erase(0, pos + delimiter.length());
        }
        tokens.push_back(s);

        return tokens;
    }

    std::string trim(std::string &s) {
        int l = 0, r = s.size()-1;
        while(l < r && (s[l] == ' ' || s[r] == ' ')) {
            if (s[l] == ' ') {
                ++l;
            }
            if (s[r] == ' ') {
                --r;
            }
        }
        return s.substr(l, r-l+1);
    }
}
