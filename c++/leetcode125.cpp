//
// Created by Kesu Peterill on 7/1/2024.
//
#include "all.h"

class leetcode125 {
public:
    bool sol(string s) {
        int table[128];
        int i = 0;
        for (; i < 48; i++) {
            table[i] = -1;
        }
        for (; i < 58; i++) {
            table[i] = i;
        }
        for (; i < 65; i++) {
            table[i] = -1;
        }
        for (; i < 91; i++) {
            table[i] = i+32;
        }
        for (; i < 97; i++) {
            table[i] = -1;
        }
        for (; i < 123; i++) {
            table[i] = i;
        }
        for (; i < 128; i++) {
            table[i] = -1;
        }
        int left = 0;
        int right = s.size()-1;
        while (left<right) {
            if (table[s.at(left)] == -1) {
                left ++;
                continue;
            }
            if (table[s.at(right)] == -1) {
                right --;
                continue;
            }
            char l,r;
            if (table[s.at(left)] != table[s.at(right)]) {
                return false;
            }
            left ++;
            right --;
        }
        return true;
    }
};