//
// Created by Kesu Peterill on 8/2/2024.
//
#include "all.h"

class leetcode167 {
public:
    vector<int> sol(vector<int>& numbers, int target) {
        if (numbers.size() == 2)
            return {1,2};
        int left = 0;
        int right = numbers.size()-1;

        while (true) {
            int sum = numbers.at(left) + numbers.at(right);
            if (sum == target)
                return {1+left, 1+right};
            if (sum < target) {
                left ++;
            } else {
                right --;
            }
        }
    }
};