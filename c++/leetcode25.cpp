//
// Created by Kesu Peterill on 5/28/2024.
//
#include "all.h"

class leetcode25 {
public:
    ListNode* sol(ListNode* head, int k) {
        auto *ans = new ListNode(0);
        ans->next = head;
        auto *cur = ans;
        while (true) {
            //Reverse from cur->next to end;
            ListNode *end;
            if ((end = getK(cur, k)) == nullptr) {
                break;
            }
            //Keep everything after the reverse nodes
            ListNode *afterReverse = end->next;

            end->next = nullptr;
            //Keep track of the first node which will be the last node after reverse
            ListNode *last = cur->next;

            cur->next = reverseNodes(cur->next);
            cur = last;
            cur->next = afterReverse;
        }
        return ans->next;
    }
    ListNode* getK(ListNode* cur, int k) {
        for (int i = 0; i < k; i++) {
            if (cur->next == nullptr)
                return nullptr;
            cur = cur->next;
        }
        return cur;
    }
    //Return the last node
    ListNode *reverseNodes(ListNode *head) {
        ListNode *ret = new ListNode();
        while (head != nullptr) {
            ListNode *next = head->next;
            head->next = ret->next;
            ret->next = head;
            head = next;
        }
        return ret->next;
    }
};