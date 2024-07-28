//
// Created by Kesu Peterill on 6/13/2024.
//
#include "all.h"

class leetcode42 {
public:
    int ans = 0;
    int abrupt = 0;
    int trap(vector<int>& height) {
        //pair.first is the x position of the wall, pair.second is the height of the wall
        vector<pair<int, int>> walls;
        for (int i = 0; i < height.size(); i++) {
            int curHeight = height.at(i);
            if (curHeight != 0) {
                computeTrapWater(walls, i, curHeight);
            }
        }
        while (walls.size() > 1) {
            auto [backX, backY] = walls.back();
            walls.pop_back();
            auto [frontX, frontY] = walls.back();
            ans += (backX - frontX - 1) * backY;
        }
        return ans - abrupt;
    }
    void computeTrapWater(vector<pair<int, int>>& walls, int x, int h) {
        while (!walls.empty()) {
            auto [wallsX, wallsY] = walls.back();
            if (wallsY >= h) {
                break;
            }
            if (walls.size() == 1) {
                int trapWater = wallsY * (x-1-wallsX);
                ans += trapWater - abrupt;
                abrupt = 0;
            } else {
                abrupt += wallsY;
            }
            walls.pop_back();
        }
        walls.emplace_back(x, h);
    }
};