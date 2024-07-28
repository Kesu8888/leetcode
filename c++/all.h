//
// Created by Kesu Peterill on 5/28/2024.
//

#ifndef C___ALL_H
#define C___ALL_H

#endif //C___ALL_H
#include "vector"
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct DDL {
    int val;
    int key;
    DDL *next;
    DDL *prev;
    DDL() : val(0), next(nullptr) {}
    DDL(int x, int y) : key(x), val(y), next(nullptr), prev(nullptr) {}
    DDL(int x) : val(x), next(nullptr), prev(nullptr) {}
};

struct TreeNode {
int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};