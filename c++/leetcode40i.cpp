//
// Created by Kesu Peterill on 6/11/2024.
//
#include "all.h"
// New method
class leetcode40i {
public:
    set<vector<int>> s;
    void fn(vector<int>& candidates, int target, int i, vector<int> v, int sum) {
        if (sum == target) {
            sort(v.begin(), v.end());
            s.insert(v);
            return;
        }
        for (int j = i; j < candidates.size(); j++) {
            if (j > i && candidates.at(j) == candidates.at(j - 1)) {
                continue;
            }
            if (sum + candidates.at(j) <= target) {
                v.push_back(candidates.at(j));
                fn(candidates, target, j + 1, v, sum + candidates.at(j));
                v.pop_back();
            }
        }
    }
    vector<vector<int>> sol(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        fn(candidates, target, 0, {}, 0);
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }

};