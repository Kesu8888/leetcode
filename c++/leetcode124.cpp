//
// Created by Kesu Peterill on 6/28/2024.
//
#include "all.h"

class leetcode124 {
public:
    int maximum = INT_MIN;
    int sol(TreeNode* root) {
        getSum(root);
        return maximum;
    }

    int getSum(TreeNode* root) {
        int Left = 0;
        int Right = 0;
        if (root->left != nullptr) {
            Left = getSum(root->left);
            Left = (Left <= 0) ? 0 : Left;
        }
        if (root->right != nullptr) {
            Right = getSum(root->right);
            Right = (Right <= 0) ? 0 : Right;
        }
        int curMax = root->val + Left + Right;
        maximum = max(maximum, curMax);
        return root->val + max(Left, Right);
    }
};