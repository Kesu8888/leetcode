//
// Created by Kesu Peterill on 7/24/2024.
//
#include "all.h"

class leetcode135 {
public:
    int sol(vector<int>& ratings) {
        vector<int> candy(ratings.size(), 0);
        candy[0] = 1;
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings.at(i) > ratings.at(i-1)) {
                candy.at(i) = candy.at(i-1)+1;
                continue;
            }
            if (ratings.at(i) == ratings.at(i-1)) {
                candy.at(i) = 1;
                continue;
            }
            int j = i-1;
            do {
                i++;
            }
            while (i < ratings.size() && ratings.at(i) < ratings.at(i-1));
            i--;
            redistribute(candy, i, j);
        }
        int sum = 0;
        for (int i : candy) {
            sum += i;
        }
        return sum;
    }

    void redistribute(vector<int>& candy, int last, int first) {
        candy.at(last) = 1;
        for (int i = last-1; i > first; i--) {
            candy.at(i) = candy.at(i+1)+1;
        }
        candy.at(first) = max(candy.at(first), candy.at(first+1)+1);
    }
};