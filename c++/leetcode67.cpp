//
// Created by Kesu Peterill on 6/22/2024.
//
#include "all.h"

class leetcode67 {
public:
    string sol(string a, string b) {
        int remaining = 0;
        string Long = (a.size() > b.size()) ? a:b;
        string Short = (a.size() > b.size()) ? b:a;
        int i = Long.size()-1;
        int j = Short.size() - 1;
        while (i >= 0) {
            char S = (j < 0) ? '0':Short[j];
            char sum = Long[i] + S - '0' + remaining;
            if (sum >= '2') {
                remaining = 1;
                Long[i] = sum - 2;
            } else {
                Long[i] = sum;
                remaining = 0;
            }
            i--;
            j--;
        }
        if (remaining == 1) {
            return '1' + Long;
        }
        return Long;
    }
};