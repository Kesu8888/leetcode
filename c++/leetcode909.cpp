//
// Created by Kesu Peterill on 6/12/2024.
//
#include "all.h"

//BFS method
class leetcode909 {
public:
    int sol(vector<vector<int>>& board) {
        int n = board.size();
        int squareNo = 1;
        vector<pair<int, int>> square(n * n + 1);
        vector<int> column(n);
        iota(column.begin(), column.end(), 0);
        for (int row = n - 1; row >= 0; row --) {
            for (int col : column) {
                square[squareNo++] = {row, col};
            }
            reverse(column.begin(), column.end());
        }
        queue<int> q;
        q.push(1);
        vector<int> dist(n*n + 1, -1);
        dist[1] = 0;
        while (!q.empty()) {
            int curSquare = q.front();
            q.pop();
            for (int i = curSquare+1; i <= min(n*n, curSquare + 6); i++) {
                int next = (board[square[i].first][square[i].second] == -1) ?
                        i : board[square[i].first][square[i].second];
                if (dist[next] == -1) {
                    dist[next] = 1 + dist[curSquare];
                    q.push(next);
                }
            }
        }
        return dist[n*n];
    }
};