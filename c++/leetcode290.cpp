//
// Created by Kesu Peterill on 6/26/2024.
//
#include "all.h"

class leetcode290 {
public:
    bool sol(string pattern, string s) {
        unordered_map<char, string> m;
        set<string> Set;
        int i = 0;
        int j = 0;
        while (i < pattern.size() && j < s.size()) {
            string word;
            while (j < s.size()) {
                if (s.at(j) == ' ') {
                    j++;
                    break;
                }
                word += s.at(j);
                j++;
            }

            if (!m.contains(pattern.at(i))) {
                if (Set.contains(word)) {
                    return false;
                }
                Set.insert(word);
                m.insert({pattern.at(i), word});
            }
            if (m.at(pattern.at(i)) != word) {
                return false;
            }
            i++;
        }
        if (i == pattern.size() && j == s.size()) {
            return true;
        }
        return false;
    }
};