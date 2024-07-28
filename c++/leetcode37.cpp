//
// Created by Kesu Peterill on 6/8/2024.
//
#include "all.h"

class leetcode37 {
public:
    bool row[9][10] = {}, col[9][10] = {}, sub[9][10] = {};
    void add(int i, int j, int num) {

        row[i][num] = true;
        col[j][num] = true;
        int s = (j/3) + (i/3) * 3;
        sub[s][num] = true;
    }
    void remove(int i, int j, int num) {
        row[i][num] = false;
        col[j][num] = false;
        int s = (j/3) + (i/3) * 3;
        sub[s][num] = false;
    }
    bool next(int i, int j, vector<vector<char>>& board) {
        j ++;
        if (j == 9) {
            j = 0;
            i ++;
        }
        if (i == 9) {
            return true;
        }
        if (board[i][j] != '.') {
            return next(i, j, board);
        } else {
            int s = (j/3) + (i/3) * 3;
            for (char k = '1'; k <= '9'; k++) {
                int num = k - '0';
                if (row[i][num] || col[j][num] || sub[s][num]) {
                    continue;
                }
                add(i, j, num);
                if (next(i, j, board)) {
                    board[i][j] = k;
                    return true;
                }
                remove(i, j, num);
            }
            return false;
        }
    }
    void sol(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    add(i, j, board[i][j] - '0');
                }
            }
        }
        next(0, -1, board);
    }
};