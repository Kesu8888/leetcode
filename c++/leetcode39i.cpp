//
// Created by Kesu Peterill on 6/10/2024.
//
//Better solution for leetcode 39
#include "all.h"

class leetcode39i {
public:
    vector<vector<int>> sol(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        sum(candidates, target, ans, v, 0);
        return ans;
    }
    void sum(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& v, int index) {
        if (target == 0) {
            ans.emplace_back(v);
            return;
        }
        if (target < 0) {
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            v.push_back(candidates.at(i));
            sum(candidates, target - candidates.at(i), ans, v, i);
            v.pop_back();
        }
    }
};