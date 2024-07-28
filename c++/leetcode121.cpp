//
// Created by Kesu Peterill on 6/19/2024.
//
#include "all.h"

class leetcode121 {
public:
    int sol(vector<int>& prices) {
        int lowestPrice = INT_MAX;
        int profit = 0;
        for (int i : prices) {
            if (i < lowestPrice) {
                lowestPrice = i;
            } else {
               profit = max(profit, i-lowestPrice);
            }
        }
        return profit;
    }
};