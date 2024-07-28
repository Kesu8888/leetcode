//
// Created by Kesu Peterill on 6/7/2024.
//
#include "all.h"

class leetcode35 {
public:
    int sol(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            int mid = (start + end)/2;
            if (nums.at(mid) == target) {
                return mid;
            }
            if (nums.at(mid) < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return start;
    }
};