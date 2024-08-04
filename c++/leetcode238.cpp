//
// Created by Kesu Peterill on 8/3/2024.
//
#include "all.h"

class leetcode238 {
public:
    vector<int> sol(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n);
        output.push_back(nums.at(0));
        for (int i = 1; i < n; i++) {
            output[i] = nums[i]*output.back();
        }

        int back = output.at(n-2);
        for (int i = n - 2; i > 0; i--) {
            output.at(i) = output.at(i-1) * nums.at(i+1);
            nums.at(i) *= nums.at(i+1);
        }
        output.back() = back;
        output.front() = nums.at(1);
        return output;
    }
};