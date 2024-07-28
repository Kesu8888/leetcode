//
// Created by Kesu Peterill on 6/22/2024.
//
#include "all.h"

class leetcode53 {
public:
    int sol(vector<int>& nums) {
        int max_ending = 0;
        int max_sofar = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            max_ending = max_ending + nums.at(i);
            if (max_sofar < max_ending) {
                max_sofar = max_ending;
            }
            if (max_ending < 0) {
                max_ending = 0;
            }
        }
        return max_sofar;
    }
};