//
// Created by Kesu Peterill on 7/10/2024.
//
#include "all.h"

class leetcode274 {
public:
    int sol(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int i = 0;
        int min = 0;
        while (i < citations.size() && citations.at(i) < citations.size()-i) {
            min = citations.at(i);
            i ++;
        }
        min = max(min, (int)citations.size()-i);
        return min;
    }
};