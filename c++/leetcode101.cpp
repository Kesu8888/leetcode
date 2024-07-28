//
// Created by Kesu Peterill on 6/25/2024.
//
#include "all.h"

class leetcode101 {
public:
    bool sol(TreeNode* root) {
        return isSame(root->left, root->right);
    }
    bool isSame(TreeNode* left, TreeNode* right) {
        if (left == nullptr) {
            return right == nullptr;
        }
        if (right == nullptr) {
            return false;
        }
        bool ans = left->val == right->val && isSame(left->right, right->left) && isSame(left->left, right->right);
        return ans;
    }
};