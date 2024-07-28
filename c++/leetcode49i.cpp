//
// Created by Kesu Peterill on 6/24/2024.
//
#include "all.h"

class leetcode49i {
public:
    vector<vector<string>> sol(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> result;
        unordered_map<string, vector<string>> hash;
        string value;
        for (int i = 0; i < n; i++){
            value = strs[i];
            sort(value.begin(), value.end());
            hash[value].push_back(strs[i]);
        }
        for (auto i : hash) result.push_back(i.second);

        return result;
    }
};