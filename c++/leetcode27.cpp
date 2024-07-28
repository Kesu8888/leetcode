//
// Created by Kesu Peterill on 5/30/2024.
//
#include "all.h"

class leetcode27 {
public:
    int sol(vector<int>& nums, int val) {
        if (nums.empty()) {
            return 0;
        }
        int last = nums.size() - 1;
        int first = 0;
        while (first <= last) {
            if (nums.at(first) == val) {
                nums.at(first) = nums.at(last);
                last --;
            } else {
                first ++;
            }
        }
        return last;
    }
};