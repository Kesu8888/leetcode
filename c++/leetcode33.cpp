//
// Created by Kesu Peterill on 6/5/2024.
//
#include "all.h"

class leetcode33 {
public:
    int sol(vector<int>& nums, int target) {
        if (nums.size() == 1) {
            return target == nums.at(0);
        }
        //Check if the array is rotated in the middle
        if (nums.at(0) > nums.at(nums.size() - 1)) {
            int biggestNumIndex = RBST(nums, 0, nums.size() - 2, nums.at(nums.size() - 1));
            if (target > nums.at(nums.size() - 1)) {
                return BST(nums, 0, biggestNumIndex, target);
            } else {
                return BST(nums, biggestNumIndex + 1, nums.size() - 1, target);
            }
        } else {
            return BST(nums, 0, nums.size() - 1, target);
        }
    }
private:
    int BST(vector<int>& nums, int start, int end, int target) {
        if (start > end) {
            return -1;
        }
        int index = start + (end - start)/2;
        int num = nums.at(index);
        if (num == target) {
            return index;
        } else if (num > target) {
            return BST(nums, start, index - 1, target);
        } else {
            return BST(nums, index + 1, end, target);
        }
    }
    //This is to find the first number that is smaller than the previous number in the rotated array nums
    int RBST(vector<int>& nums, int start, int end, int target) {
        if (end - start <= 0) {
            return (nums.at(start) > target) ? start : start - 1;
        }
        int index = start + (end - start)/2;
        int num = nums.at(index);
        if (num < target) {
            return RBST(nums, start, index - 1, target);
        }
        return RBST(nums, index + 1, end, target);
    }
};