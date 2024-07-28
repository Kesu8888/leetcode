//
// Created by Kesu Peterill on 6/25/2024.
//
#include "all.h"

class leetcode105 {
public:
    TreeNode* sol(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, TreeNode*> passThrough;
        passThrough.insert({preorder[0], new TreeNode(preorder[0])});
        int j;
        for (int i = 1; i < preorder.size(); i++) {
            TreeNode* node = new TreeNode(preorder[i]);
            if (preorder.at(i-1) == inorder.at(j)) {
                while (passThrough.contains(inorder[j])) {
                    j++;
                }
                passThrough.at(inorder[j-1])->right = node;
            } else {
                passThrough.at(preorder[i-1])->left = node;
            }
            passThrough.insert({preorder[i], node});
        }
        return passThrough.at(preorder[0]);
    }
    void displayTree(TreeNode* node) {
        if (node == nullptr) {
            cout << "null" << " ";
            return;
        }
        cout << node->val << " ";
        displayTree(node->left);
        displayTree(node->right);
    }
};

