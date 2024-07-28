//
// Created by Kesu Peterill on 5/27/2024.
//

#include "all.h"

class leetcode23 {
public:
    ListNode* sol(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<>> pq;
        for (ListNode* l : lists) {
            if (l != nullptr) {
                pq.push({l->val, l});
            }
        }
        auto* ans = new ListNode();
        auto* cur = ans;
        while (!pq.empty()) {
            ListNode* min = pq.top().second;
            pq.pop();
            cur->next = min;
            if (min->next != nullptr) {
                pq.push({min->next->val, min->next});
            }
            cur = cur->next;
        }
        return ans->next;
    }
};

