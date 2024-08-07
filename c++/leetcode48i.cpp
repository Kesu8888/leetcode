//
// Created by Kesu Peterill on 6/24/2024.
//
#include "all.h"
//Better solution
class leetcode48i {
public:
    void sol(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //transposing the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //reversing each row of the matrix
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};