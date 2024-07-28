//
// Created by Kesu Peterill on 7/21/2024.
//
#include "all.h"

class leetcode92 {
public:
    ListNode* sol(ListNode* head, int left, int right) {
        ListNode* temp = head;
        reverseNodes(temp, temp, left, right, 1);
        return head;
    }
    void reverseNodes(ListNode*& start, ListNode* curNode, int left, int right, int cur) {
        if (cur == right) {
            return;
        }
        if (cur == left) {
            start = curNode;
        }
        cur ++;
        curNode = curNode->next;
        reverseNodes(start, curNode, left, right, cur);
        if (cur > (left+right)/2) {
            swap(start->val, curNode->val);
            start = start->next;
        }
    }
};