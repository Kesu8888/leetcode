//
// Created by Kesu Peterill on 8/2/2024.
//
#include "all.h"

class leetcode392 {
public:
    bool sol(string s, string t) {
        if (s.size() > t.size())
            return false;

        bool isSub = false;
        int i = 0;
        for (char c : s) {
            isSub = false;
            while (i < t.size()) {
                if (t.at(i) == c) {
                    i ++;
                    isSub = true;
                    break;
                }
                i++;
            }
        }
        return isSub;
    }
};