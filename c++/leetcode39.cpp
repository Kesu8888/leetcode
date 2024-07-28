//
// Created by Kesu Peterill on 6/10/2024.
//
#include "all.h"

class leetcode39 {
public:
    vector<vector<int>> ans;
    vector<int> can;
    vector<vector<int>> sol(vector<int>& candidates, int target) {
        can = candidates;
        sort(can.begin(), can.end());
        if (target < can.at(0)) {
            return ans;
        }
        vector<int> arg;
        for (int i = 0; i < can.size(); i++) {
            next(arg, target, i);
        }
        return ans;
    }
    void next(vector<int> nums, int target, int pos) {
        int v = can.at(pos);
        nums.emplace_back(v);
        if (target - v == 0) {
            ans.emplace_back(nums);
            return;
        }
        if (target - v > 0) {
            target -= v;
            while (pos < can.size() && (target - can.at(pos)) >= 0) {
                next(nums, target, pos);
                pos++;
            }
        }
    }
};