//
// Created by Kesu Peterill on 5/29/2024.
//
#include "all.h"

class leetcode26 {
public:
    int sol(vector<int>& nums) {
        int curPos = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums.at(i) == nums.at(curPos)) {
                continue;
            }
            curPos += 1;
            nums.at(curPos) = nums.at(i);
        }
        return curPos + 1;
    }
};