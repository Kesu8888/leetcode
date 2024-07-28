//
// Created by Kesu Peterill on 7/14/2024.
//
#include "all.h"

class leetcode452{
public:
    int sol(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        for (vector<int> v : points) {
            cout << "(" << v[0] << "," << v[1] << "), ";
        }
        vector<int> previous = points.at(0);
        int arrowNO = 1;
        for (int i = 1; i < points.size(); i++) {
            vector<int> cur = points.at(i);
            if (previous.at(1) >= cur.at(0)) {
                previous.at(0) = cur.at(0);
                previous.at(1) = min(previous[1], cur[1]);
            } else {
                previous = cur;
                arrowNO ++;
            }
        }
        return arrowNO;
    }
};