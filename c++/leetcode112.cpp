//
// Created by Kesu Peterill on 7/27/2024.
//
#include "all.h"

class leetcode {
public:
    bool sol(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return false;
        return validPath(root, targetSum);
    }

    bool validPath(TreeNode* root, int targetSum) {
        targetSum = targetSum - root->val;
        if (!root->left && !root->right)
            return !targetSum;
        if (!root->left)
            return validPath(root->right, targetSum);
        if (!root->right)
            return validPath(root->left, targetSum);
        return validPath(root->right, targetSum) || validPath(root->left, targetSum);
    }
};