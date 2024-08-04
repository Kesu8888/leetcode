//
// Created by Kesu Peterill on 8/3/2024.
//
#include "all.h"

class leetcode151 {
public:
    string sol(string s) {
        vector<string> storage;
        string str;
        for (char c : s) {
            if (c == ' ') {
                if (!str.empty()) {
                    storage.push_back(str);
                    str.clear();
                }
                continue;
            }
            str.push_back(c);
        }
        if (!str.empty())
            storage.push_back(str);
        if (storage.empty())
            return "";
        str.clear();
        str.append(storage.back());
        for (int i = storage.size()-2; i >= 0; i--) {
            str.push_back(' ');
            str.append(storage.at(i));
        }
        return str;
    }
};