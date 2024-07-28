//
// Created by Kesu Peterill on 7/11/2024.
//
#include "all.h"

class leetcode73i {
public:
    void sol(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int rowarr[200] = {0};
        int colarr[200] = {0};

        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(matrix[i][j] == 0)
                {
                    rowarr[i] = 1;
                    colarr[j] = 1;
                }
            }
        }
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(rowarr[i] || colarr[j])
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};