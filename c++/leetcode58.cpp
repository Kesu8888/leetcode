//
// Created by Kesu Peterill on 8/2/2024.
//
#include "all.h"

class leetcode58 {
public:
    int sol(string s) {
        int i = s.size()-1;
        while (s.at(i) == ' ')
            i --;
        int j = i-1;
        while (j>=0) {
            if (s.at(j) == ' ')
                break;
            j --;
        }
        return i - j;
    }
};