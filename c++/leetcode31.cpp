//
// Created by Kesu Peterill on 6/3/2024.
//
#include "all.h"

class leetcode31 {
public:
    void sol(vector<int>& nums) {
        int i = nums.size() - 1;
        while (i > 0) {
            //We found the number that should be swaped
            if (nums.at(i) > nums.at(i - 1)) {
                int tobeswap = i;
                while (tobeswap < nums.size() - 1) {
                    if (nums.at(i - 1) >= nums.at(tobeswap + 1)) {
                        break;
                    }
                    tobeswap += 1;
                }
                int temp = nums.at(tobeswap);
                nums.at(tobeswap) = nums.at(i - 1);
                nums.at(i - 1) = temp;
                swap(nums, i);
                return;
            }
            i --;
        }
        swap(nums, 0);
    }
    void swap(vector<int>& nums, int start) {
        unsigned left = start;
        unsigned right = nums.size() - 1;
        while (left < right) {
            int temp = nums.at(left);
            nums.at(left) = nums.at(right);
            nums.at(right) = temp;
            left ++;
            right --;
        }
    }
};