//
// Created by Kesu Peterill on 7/23/2024.
//
#include "all.h"

//Faster method
class leetcode138i {
public:
    Node* sol(Node* head) {
        if(head == NULL) {
            return NULL;
        }

        Node* curr = head;

        // add new nodes in between the existing nodes:
        while(curr != NULL) {
            Node* newNode = new Node(curr->val);
            Node* next = curr->next;
            curr->next = newNode;
            newNode->next = next;
            curr = next;
        }

        // set random pointers:
        curr = head;
        while(curr != NULL) {
            Node* newNode = curr->next;

            if(curr->random != NULL) {
                newNode->random = curr->random->next;
            }

            curr = curr->next->next;
        }

        // split out the two linked lists:
        Node* resultLL = head->next;
        curr = head;

        while(curr != NULL) {
            Node* next = curr->next;

            if(curr->next != NULL) {
                curr->next = curr->next->next;
            }

            curr = next;
        }

        return resultLL;
    }
};