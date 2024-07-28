//
// Created by Kesu Peterill on 6/12/2024.
//
//Better runtime variant

#include "all.h"

class leetcode41i {
public:
    int sol(vector<int>& nums) {
        for(int i=0;i<nums.size();) {
            if((long)nums[i]-1<nums.size() && (long)nums[i]-1>=0 && nums[i]!=nums[(long)nums[i]-1]) {
                int t=nums[(long)nums[i]-1];
                nums[(long)nums[i]-1]=nums[i];
                nums[i]=t;
            }
            else {
                i++;
            }
        }
        for(int i=0;i<nums.size();i++) {
            if(i+1!=nums[i]) {
                return i+1;
            }
        }
        return nums.size()+1;
    }
};