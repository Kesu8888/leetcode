//
// Created by Kesu Peterill on 5/31/2024.
//
#include "all.h"
class leetcode209 {
public:
    int sol(int target, vector<int>& nums) {
        int i = 0;
        int j = 0;
        int mini = INT_MAX;
        int sum = 0;
        // Looping until the last element
        while (j < nums.size()) {
            sum += nums[j];
            while (sum >= target) {
               mini = min(mini, (j - i));
               sum = sum - nums[i];
               i ++;
            }
            j ++;
        }
        return sum;
    }
};