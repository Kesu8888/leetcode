//
// Created by Kesu Peterill on 7/3/2024.
//
#include "all.h"

class leetcode189m1 {
public:
    void sol(vector<int>& nums, int k) {
        int pos = nums.size()-(k%nums.size());
        vector<int> front = {nums.begin()+pos, nums.end()};
        nums.erase(nums.begin()+pos, nums.end());
        front.insert(front.end(),nums.begin(), nums.end());
        nums = front;
    }
};