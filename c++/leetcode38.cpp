//
// Created by Kesu Peterill on 6/10/2024.
//
#include "all.h"

class leetcode38 {
public:
    string origin = "1";
    string sol(int n) {
        for (; n > 1; n--) {
            int i = 1;
            string s;
            int count = 1;
            char prev = origin.at(0);
            while (i < origin.size()) {
                if (origin.at(i) != origin.at(i - 1)) {
                    s.append(to_string(count));
                    s += prev;
                    count = 1;
                    prev = origin.at(i);
                } else {
                    count ++;
                }
                i ++;
            }
            s.append(to_string(count));
            s += prev;
            origin = s;
        }
        return origin;
    }
};