//
// Created by Kesu Peterill on 6/4/2024.
//
#include "all.h"

class leetcode228 {
    vector<string> sol(vector<int>& nums) {
        vector<string> ans;
        if (nums.size() == 0) {
            ans.emplace_back("");
            return ans;
        }
        int left = 0;
        int right = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums.at(i) + 1 == nums.at(i + 1)) {
                right += 1;
            } else {
                if (left == right) {
                    ans.emplace_back(to_string(nums.at(left)));
                } else {
                    string s = to_string(nums.at(left)).append("->");
                    s.append(to_string(nums.at(right)));
                    ans.emplace_back(s);
                }
                left = right = i + 1;
            }
        }
        if (left == right) {
            ans.emplace_back(to_string(nums.at(left)));
        } else {
            string s = to_string(nums.at(left)).append("->");
            s.append(to_string(nums.at(right)));
            ans.emplace_back(s);
        }
        return ans;
    }
};