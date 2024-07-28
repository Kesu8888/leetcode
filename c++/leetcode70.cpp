//
// Created by Kesu Peterill on 6/5/2024.
//
#include "all.h"

class leetcode70 {
public:
    int sol(int n) {
        if (n <= 3) {
            return n;
        }
        int prev = 2;
        int cur = 3;
        for (int i = 3; i < n; i++) {
            int temp = cur;
            cur = cur + prev;
            prev = temp;
        }
        return cur;
    }
};