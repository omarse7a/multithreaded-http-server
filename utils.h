//
// Created by crazy-penguin on 5/10/25.
//

#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

namespace utils {
    // time complexity: O(N) where N is the size of s
    // splits(optional): maximum number of splits, if it doesn't matter leave it as -1
    // skips(optional): number of delimiters to skip before splitting, if it doesn't matter leave it as 0
    std::vector<std::string> split(const std::string& s, const char& delimiter, int splits = -1, int skips = 0);
    // time complexity: O(N*M) where N is the size of s and M is the # of delimiters in s
    // in the worst case where all chars of s are delimiters, time complexity: O(N^2)
    std::vector<std::string> split(std::string s, const std::string& delimiter);
    std::string trim(std::string& s);
};



#endif //UTILS_H
