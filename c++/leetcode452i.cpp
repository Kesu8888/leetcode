//
// Created by Kesu Peterill on 7/14/2024.
//
#include "all.h"

class leetcode452i {
public:
    int sol(vector<vector<int>>& points) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        sort(points.begin(), points.end());
        // reverse(points.begin(), points.end());
        int arrows = 1;
        int end = points[0][1];

        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > end) {
                arrows++;
                end = points[i][1];
            }
            else {
                end = min(end, points[i][1]);
            }
        }
        return arrows;
    }
};