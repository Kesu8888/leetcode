//
// Created by Kesu Peterill on 5/28/2024.
//

#include "all.h"

class leetcode24 {
public:
    ListNode* sol(ListNode* head) {
        auto* ans = new ListNode(0);
        ans->next = head;
        auto *cur = ans;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            ListNode *next = cur->next->next;
            cur->next->next = cur->next->next->next;
            next->next = cur->next;
            cur = cur->next->next;
        }
        return ans->next;
    }
};