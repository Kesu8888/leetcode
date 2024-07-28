//
// Created by Kesu Peterill on 6/15/2024.
//
#include "all.h"

class leetcode200 {
public:
    int sol(vector<vector<char>>& grid) {
        int islandNO = 0;
        set<pair<int, int>> islands;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    DFS(grid, i, j);
                    islandNO ++;
                }
            }
        }
        return islandNO;
    }
    void DFS(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != '1' ) {
            return;
        }
        grid[i][j] = '2';
        DFS(grid, i-1, j);
        DFS(grid, i, j-1);
        DFS(grid, i+1, j);
        DFS(grid, i, j+1);
    }
};