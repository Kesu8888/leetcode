//
// Created by Kesu Peterill on 6/11/2024.
//
#include "all.h"

class leetcode199 {
public:
    vector<int> sol(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) {
            return ans;
        }
        next(root, ans, 0);
        return ans;
    }
    void next(TreeNode* node, vector<int>& ans, int level) {
        if (ans.size() <= level) {
            ans.emplace_back(node->val);
        } else {
            ans.at(level) = node->val;
        }
        if (node->left != nullptr) {
            next(node->left, ans, level + 1);
        }
        if (node->right != nullptr) {
            next(node->right, ans, level + 1);
        }
    }
};