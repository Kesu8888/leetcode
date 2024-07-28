//
// Created by Kesu Peterill on 6/6/2024.
//
#include "all.h"

class leetcode100 {
public:
    bool sol(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr) {
            return p == q;
        }
        if (p->val != q->val ) {
            return false;
        }
        return sol(p->left, q->left) && sol(p->right, q->right);
    }
};