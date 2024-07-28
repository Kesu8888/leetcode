//
// Created by Kesu Peterill on 7/20/2024.
//
#include "all.h"

class BSTIterator {
public:
    deque<int> nodes;
    BSTIterator(TreeNode* root) {
        preOrder(root);
    }

    void preOrder(TreeNode* root) {
        if (!root) {
            return;
        }
        preOrder(root->left);
        nodes.push_back(root->val);
        preOrder(root->right);
    }
    int next() {
        int temp = nodes.front();
        nodes.pop_front();
        return temp;
    }

    bool hasNext() {
        return !nodes.empty();
    }
};