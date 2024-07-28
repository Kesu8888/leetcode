//
// Created by Kesu Peterill on 7/13/2024.
//
#include "all.h"

class leetcode114 {
public:
    void sol(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        getNext(root);
    }
    TreeNode* getNext(TreeNode* node) {
        TreeNode* end = node;
        if (node->right != nullptr) {
            TreeNode* right = node->right;
            if (node->left != nullptr) {
                end->right = node->left;
                node->left = nullptr;
                end = getNext(end->right);
            }
            end->right = right;
            end = getNext(right);
        } else {
            if (node->left != nullptr) {
                end->right = node->left;
                node->left = nullptr;
                end = getNext(end->right);
            }
        }
        return end;
    }
};