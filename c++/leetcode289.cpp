//
// Created by Kesu Peterill on 7/11/2024.
//
#include "all.h"

class leetcode289 {
public:
    int col;
    int row;
    void sol(vector<vector<int>>& board) {
        col = board.size();
        row = board.at(0).size();
        init(0, 0, board);
    }

    void init(int i, int j, vector<vector<int>>& board) {
        if (j == row) {
            j = 0;
            i ++;
        }
        if (i == col) {
            return;
        }
        bool res = liveOrDie(i, j, board);
        init(i, j+1, board);
        board[i][j] = res;
    }
    bool liveOrDie(int i, int j, vector<vector<int>>& board) {
        int startCol = (i>0)?(i-1):(i);
        int endCol = (i+1 < col) ? i+1:i;
        int startRow = (j>0)?(j-1):(j);
        int endRow = (j+1 < row) ? j+1:j;
        int lives = 0;
        for (int k = startCol; k <= endCol; k++) {
            for (int l = startRow; l <= endRow; l++) {
                if (board[k][l] == 1) {
                    lives ++;
                }
            }
        }
        if (board[i][j] == 1) {
            lives --;
        }
        if (lives < 2 || lives > 3) {
            return false;
        }
        if (lives == 2) {
            return board[i][j];
        }
        return true;
    }
};