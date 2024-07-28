//
// Created by Kesu Peterill on 7/14/2024.
//
#include "all.h"

class leetcode219 {
public:
    bool sol(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;
        int minV = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int value = nums.at(i);
            if (hashmap.contains(value)) {
                minV = min(minV, i-hashmap.at(value));
                hashmap.at(value) = i;
            } else {
                hashmap.insert({value, i});
            }
        }
        return minV <= k;
    }
};