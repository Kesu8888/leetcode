//
// Created by Kesu Peterill on 7/15/2024.
//
//Super fking slow method O(m*n)
#include "all.h"

class leetcode72 {
public:
    int sol(string word1, string word2) {
        vector<int> col(word2.size()+1, -1);
        vector<vector<int>> dp(word1.size()+1, col);
        return getMinDist(word1.size(), word2.size(), word1, word2, dp);
    }
private:
    int getMinDist(int i, int j, string& word1, string& word2, vector<vector<int>>& dp) {
        if (i == 0) {
            return j;
        }
        if (j == 0) {
            return i;
        }
        if (dp[i][j] >= 0) {
            return dp[i][j];
        }
        if (word1[i-1] == word2[j-1]) {
            dp[i][j] = getMinDist(i-1,j-1,word1,word2,dp);
        } else {
            int Add = 1+getMinDist(i,j-1,word1,word2,dp);
            int Replace = 1+getMinDist(i-1,j-1,word1,word2,dp);
            int Delete = 1+getMinDist(i-1,j,word1,word2,dp);
            dp[i][j] = minimum(Add,Replace,Delete);
        }
        return dp[i][j];
    }
    int minimum(int x, int y, int z) {
        int small = min(x, y);
        return min(small, z);
    }
};