//
// Created by Kesu Peterill on 7/24/2024.
//
#include "all.h"

class leetcode226 {
public:
    TreeNode* sol(TreeNode* root) {
        invert(root);
        return root;
    }

    void invert(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        invert(root->left);
        invert(root->right);
    }
};