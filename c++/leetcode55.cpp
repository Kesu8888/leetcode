//
// Created by Kesu Peterill on 7/11/2024.
//
#include "all.h"

class leetcode55 {
public:
    bool sol(vector<int>& nums) {
        int end = nums.size()-1;
        int further = 0;
        int cur = 0;
        while (further < end) {
            int tempFur = further;
            for (; cur <= tempFur; cur++) {
                further = max(further, cur+nums.at(cur));
            }
            if (tempFur == further) {
                return false;
            }
        }
        return true;
    }
};