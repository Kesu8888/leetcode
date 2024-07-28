//
// Created by Kesu Peterill on 7/1/2024.
//
#include "all.h"

class leetcode141 {
public:
    bool sol(ListNode *head) {
        int c = 100001;
        while (head != nullptr) {
            if (head->val == c) {
                return true;
            }
            head->val = c;
            head = head->next;
        }
        return false;
    }
};