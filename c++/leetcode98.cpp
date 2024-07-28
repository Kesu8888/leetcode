//
// Created by Kesu Peterill on 6/15/2024.
//
#include "all.h"

class leetcode98 {
public:
    vector<int> ans;
    bool sol(TreeNode* root) {
        if (root->right == nullptr && root->left == nullptr) {
            return true;
        }
        addNode(root);
        cout << "The size is " << ans.size() << "\n";
        for (int i = 0; i < ans.size() - 1; i++) {
            if (ans[i] >= ans[i + 1]) {
                return false;
            }
        }
        return true;
    }
    void addNode(TreeNode* node) {
        if (node->left != nullptr) {
            addNode(node->left);
        }
        ans.emplace_back(node->val);
        if (node->right != nullptr) {
            addNode(node->right);
        }
    }
};