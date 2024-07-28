//
// Created by Kesu Peterill on 7/9/2024.
//
#include "all.h"

class LRUCache {
public:
    int size;
    unordered_map<int, DDL*> keyPairs;
    DDL* head;
    DDL* back;
    LRUCache(int capacity) {
        size = capacity;
        head = new DDL(10001);
        back = new DDL(10002);
        head->next = back;
        back->prev = head;
    }
    int get(int key) {
        if (keyPairs.contains(key)) {
            DDL *newNode = keyPairs.at(key);
            newNode->prev->next = newNode->next;
            newNode->next->prev = newNode->prev;
            newNode->next = head->next;
            newNode->next->prev = newNode;
            head->next = newNode;
            newNode->prev = head;
            return keyPairs.at(key)->val;
        }
        return -1;
    }

    void put(int key, int value) {
        DDL* newNode;
        if (keyPairs.contains(key)) {
            newNode = keyPairs.at(key);
            newNode->prev->next = newNode->next;
            newNode->next->prev = newNode->prev;
            newNode->val = value;
        } else {
            if (keyPairs.size()+1 > size) {
                DDL *removed = back->prev;
                keyPairs.erase(removed->key);
                removed->prev->next = removed->next;
                removed->next->prev = removed->prev;
            }
            newNode = new DDL(key, value);
            keyPairs.insert({key, newNode});
        }
        newNode->next = head->next;
        newNode->next->prev = newNode;
        head->next = newNode;
        newNode->prev = head;
    }
};