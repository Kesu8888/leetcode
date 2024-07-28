//
// Created by Kesu Peterill on 5/30/2024.
//
#include "all.h"
class leetcode80 {
public:
    int sol(vector<int>& nums) {
        int occur = 1;
        int avail = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums.at(i) == nums.at(i - 1)) {
                if (occur >= 2) {
                    continue;
                }
                nums.at(avail) = nums.at(i);
                occur ++;
            } else {
                nums.at(avail) = nums.at(i);
                occur = 1;
            }
            avail ++;
        }
        return avail;
    }
};