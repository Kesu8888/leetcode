//
// Created by Kesu Peterill on 7/11/2024.
//
#include "all.h"

class leetcode73 {
public:
    void sol(vector<vector<int>>& matrix) {
        int col = matrix.size();
        int row = matrix[0].size();
        set<int> deleteCol;
        set<int> deleteRow;

        for (int i = 0; i < col; i++) {
            for (int k = 0; k < row; k++) {
                if (matrix[i][k] == 0) {
                    deleteCol.insert(i);
                    deleteRow.insert(k);
                }
            }
        }

        for (int i : deleteCol) {
            for (int k = 0; k < row; k++) {
                matrix[i][k] = 0;
            }
        }

        for (int i : deleteRow) {
            for (int k = 0; k < col; k++) {
                matrix[k][i] = 0;
            }
        }
    }
};