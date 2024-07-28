//
// Created by Kesu Peterill on 7/9/2024.
//
#include "all.h"

class leetcode86 {
public:
    ListNode* sol(ListNode* head, int x) {
        ListNode* smallHead = new ListNode(INT_MIN);
        ListNode* bigHead = new ListNode(INT_MAX);
        ListNode* small = smallHead;
        ListNode* big = bigHead;
        while (head != nullptr) {
            ListNode* temp = head;
            if (temp->val < x) {
                small->next = temp;
                small = small->next;
            } else {
                big->next = temp;
                big = big->next;
            }
            head = head->next;
            temp->next = nullptr;
        }
        small->next = bigHead->next;
        return smallHead->next;
    }
};