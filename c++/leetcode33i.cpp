//
// Created by Kesu Peterill on 6/5/2024.
//
#include "all.h"

//Another method from leetcode best runtime method
class leetcode33i {
public:
    int findRot(vector<int>& nums) {
        int first = 0, last = nums.size() - 1, mid;
        while(first <= last && first < nums.size()){
            mid = (first+last)/2;
            if(nums[mid] >= nums[0])
                first = mid + 1;
            else
                last = mid - 1;
        }
        if(first < nums.size())
            return first;
        else
            return nums.size();
    }
    int sol(vector<int>& nums, int target) {
        int first = 0, last = nums.size()-1;
        int mid;
        if(target == nums[0])
            return 0;
        else if(target < nums[0])
            first = findRot(nums);
        else
            last = findRot(nums) - 1;
        while(first <= last){
            mid = (first+last)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                last = mid - 1;
            else
                first = mid + 1;
        }
        return -1;
    }
};