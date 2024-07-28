//
// Created by Kesu Peterill on 5/31/2024.
//
#include "all.h"

class leetcode28 {
public:
    int sol(string haystack, string needle) {
        if (haystack.size() < needle.size()) {
            return -1;
        }
        for (int i = 0; i < haystack.size() - needle.size() + 1; i++) {
            if (haystack.at(i) == needle.at(0)) {
                int coincide = 1;
                int y = i + 1;
                while (coincide < needle.size() && coincide < needle.size() && haystack.at(y) == needle.at(coincide) ) {
                    y ++;
                    coincide ++;
                }
                if (coincide == needle.size()) {
                    return i;
                }
            }
        }
        return -1;
    }
};