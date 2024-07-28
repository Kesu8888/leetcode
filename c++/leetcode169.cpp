//
// Created by Kesu Peterill on 7/3/2024.
//
#include "all.h"

class leetcode169 {
public:
    int sol(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};