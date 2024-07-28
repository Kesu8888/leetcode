//
// Created by Kesu Peterill on 6/12/2024.
//
#include "all.h"

class leetcode41 {
public:
    int sol(vector<int>& nums) {
        for (int i = 0; i < nums.size();) {
            if ((long)nums[i] -1< nums.size() && (long)nums[i] >= 1 && nums[i] != nums[nums[i] - 1]) {
                int temp = nums[nums[i] - 1];
                nums.at(nums.at(i) - 1) = nums.at(i);
                nums.at(i) = temp;
            } else {
                i ++;
            }
        }
        for (int j = 0; j < nums.size(); j++) {
            if (nums.at(j) != j + 1) {
                return j + 1;
            }
        }
        return nums.size() + 1;
    }
};