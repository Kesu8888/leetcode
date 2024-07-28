//
// Created by Kesu Peterill on 7/27/2024.
//
#include "all.h"

class leetcode106 {
public:
    TreeNode* sol(vector<int>& inorder, vector<int>& postorder) {
        int i = 0;
        int j = 0;
        stack<TreeNode*> roots;
        TreeNode* prev = nullptr;
        while (j < postorder.size()) {
            if (!roots.empty() && roots.top()->val == postorder.at(j)) {
                roots.top()->right = prev;
                prev = roots.top();
                roots.pop();
                j++;
            }else if (inorder.at(i) == postorder.at(j)) {
                TreeNode* cur = new TreeNode(inorder.at(i));
                cur->left = prev;
                prev = cur;
                i++;
                j++;
            } else {
                TreeNode* cur = new TreeNode(inorder.at(i), prev, nullptr);
                roots.push(cur);
                prev = nullptr;
                i++;
            }
        }
        return prev;
    }
    void ptn(TreeNode* root) {
        if (root == nullptr)
            return;
        cout << root->val << " ";
        ptn(root->left);
        ptn(root->right);
    }
};