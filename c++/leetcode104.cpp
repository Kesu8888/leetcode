//
// Created by Kesu Peterill on 5/31/2024.
//
#include "all.h"

class leetcode104 {
public:
    int sol(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return max(1 + sol(root->left), 1 + sol(root->right));
    }

};