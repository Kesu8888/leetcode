//
// Created by Kesu Peterill on 6/24/2024.
//
#include "all.h"

class leetcode48 {
public:
    void sol(vector<vector<int>>& matrix) {
        int n = matrix.size()-1;
        int round = matrix.size()/2;
        int curRound = 0;
        while (curRound < round) {
            for (int j = curRound; j < n-curRound; j++) {
                int i = n-curRound;
                int temp1 = matrix[curRound][j];//topleft
                int temp2 = matrix[j][i];//topright
                int temp3 = matrix[i][n-j];//botright
                int temp4 = matrix[n-j][curRound];//botleft
                matrix[curRound][j] = temp4;
                matrix[j][i] = temp1;
                matrix[i][n-j] = temp2;
                matrix[n-j][curRound] = temp3;
            }
            curRound ++;
        }
    }

};