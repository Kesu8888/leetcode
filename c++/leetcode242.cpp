//
// Created by Kesu Peterill on 7/24/2024.
//
#include "all.h"

class leetcode242 {
public:
    bool sol(string s, string t) {
        if (t.size() < s.size())
            return false;
        unordered_map<char, int> hash;
        for (char c : s) {
            if (hash.contains(c)) {
                hash.at(c) ++;
            } else {
                hash.insert({c, 1});
            }
        }

        for (char c : t) {
            if (hash.contains(c) && hash.at(c) > 0) {
                hash.at(c) --;
            } else {
                return false;
            }
        }
        return true;
    }
};