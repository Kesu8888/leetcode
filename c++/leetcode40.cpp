//
// Created by Kesu Peterill on 6/11/2024.
//
#include "all.h"
// This is the old method which exceed the time limit. The reason is that it
// only skip the same element number for the first index. The new method leetcode40i from leetcode solutions
// Skips the same element for every index.
class leetcode40 {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        unordered_map<int, vector<int>> map1;
        vector<int> v;
        sum(map1, candidates, v, target, 0, 0);
        for (int i = 1; i < candidates.size(); i++) {
            if (candidates.at(i) != candidates.at(i - 1)) {
                sum(map1, candidates, v, target, i, 0);
            }
        }
        vector<vector<int>> ans;
        for (pair<int, vector<int>> p : map1) {
            ans.emplace_back(p.second);
        }
        return ans;
    }
    void sum(unordered_map<int, vector<int>>& map1, vector<int>& candidates, vector<int>& v, int target, int index, int hashcode) {
        v.emplace_back(candidates.at(index));
        target = target - candidates.at(index);
        hashcode += pow(candidates.at(index), 4);
        if (target == 0) {
            if (!map1.count(hashcode)) {
                map1.insert(make_pair(hashcode, v));
            }
        } else if (target > 0) {
            for (int i = index + 1; i < candidates.size(); i++) {
                sum(map1, candidates, v, target, i, hashcode);
            }
        }
        v.pop_back();
    }
};