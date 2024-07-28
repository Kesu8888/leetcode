//
// Created by Kesu Peterill on 5/27/2024.
//
#include "all.h"


class leetcode21 {
public:
     ListNode* sol(ListNode* list1, ListNode* list2) {
         if (list1 == nullptr || list2 == nullptr) {
             return (list1 == nullptr) ? list1 : list2;
         }
         auto *ans = new ListNode();
         auto *cur = ans;
         while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
         }
         if (list1 == nullptr) {
             cur->next = list2;
         } else {
             cur->next = list1;
         }
         return ans->next;
     }
};