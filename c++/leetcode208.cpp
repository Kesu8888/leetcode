//
// Created by Kesu Peterill on 6/17/2024.
//
#include "all.h"

class Trie {
    struct trie {
        unordered_map<char, trie> next;
        trie() {
            next.clear();
        }
    };
public:
    set<string> bottle;
    trie root;
    Trie() {

    }
    void insert(string word) {
        if (bottle.contains(word)) {
            return;
        }
        trie node = root;
        for (char c : word) {
          if (!node.next.contains(c)) {
              root.next.insert({c, trie()});
          }
          node = root.next.at(c);
        }
        bottle.insert(word);
    }

    bool search(string word) {
        return bottle.contains(word);
    }

    bool startsWith(string prefix) {
        trie node = root;
        for (char c : prefix) {
            if (!node.next.contains(c)) {
                return false;
            }
            node = root.next.at(c);
        }
        return true;
    }
};