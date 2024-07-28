//
// Created by Kesu Peterill on 7/12/2024.
//
#include "all.h"

class leetcode230 {
public:
    TreeNode* ans;
    int sol(TreeNode* root, int k) {
        return getSmallest(root, k);
    }
    int getSmallest(TreeNode* root, int& k) {
        if(root==NULL) return -1;
        int left=getSmallest(root->left,k);
        k--;
        if(k==0){
            return root->val;
        }
        int right=getSmallest(root->right,k);
        if(left==-1) return right;
        else return left;
    }
};