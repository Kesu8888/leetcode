//
// Created by Kesu Peterill on 6/19/2024.
//
#include "all.h"

class leetcode45 {
public:
    int sol(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int jumps = 0;
        int currentEnd = nums.at(0);
        int furthest = 0;
        for (int i = 0; i < nums.size()-1; i++) {
            furthest = max(furthest, i+nums.at(i));

            if (i == currentEnd) {
                jumps ++;
                currentEnd = furthest;
            }
        }
        return jumps+1;
    }
};