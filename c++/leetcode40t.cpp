//
// Created by Kesu Peterill on 6/23/2024.
//
#include "all.h"

class leetcode40t {
public:
    set<vector<int>> s;
    vector<vector<int>> sol(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> nums;
        nextSum(nums, target, candidates, 0);
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
    void nextSum(vector<int>& nums, int target, vector<int>& candidates, int index) {
        if (target == 0) {
            s.insert(nums);
            return;
        }
        if (target < 0) {
            return;
        }
        if (index < candidates.size()) {
            for (int i = index; i < candidates.size(); i++) {
                if (i > index && candidates[i] == candidates[i-1]) {
                    continue;
                }
                nums.push_back(candidates[i]);
                nextSum(nums, target-candidates[i], candidates, i);
                nums.pop_back();
            }
        }
    }
};