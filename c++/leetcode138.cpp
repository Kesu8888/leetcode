//
// Created by Kesu Peterill on 7/23/2024.
//
#include "all.h"

class leetcode138 {
public:
    Node* sol(Node* head) {
        unordered_map<Node*, Node*> NodeList;
        Node* start = new Node(0);
        Node* i = start;
        Node* j = head;
        while (j != nullptr) {
            if (NodeList.contains(j)) {
                i->next = NodeList.at(j);
            } else {
                i->next = new Node(j->val);
                NodeList.insert({j, i->next});
            }
            i = i->next;

            if (j->random != nullptr) {
                Node* random = j->random;
                if (NodeList.contains(random)) {
                    i->random = NodeList.at(random);
                } else {
                    i->random = new Node(random->val);
                    NodeList.insert({random, i->random});
                }
            }

            j = j->next;
        }
        return start->next;
    }
};