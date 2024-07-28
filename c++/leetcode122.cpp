//
// Created by Kesu Peterill on 6/19/2024.
//
#include "all.h"

class leetcode122 {
public:
    int sol(vector<int>& prices) {
        int stockPrice = INT_MAX;
        int profit = 0;
        for (int i : prices) {
            if (i < stockPrice) {
                stockPrice = i;
            } else {
                profit += i-stockPrice;
                stockPrice = i;
            }
        }
        return profit;
    }
};