//
// Created by Kesu Peterill on 6/4/2024.
//
#include "all.h"

class leetcode32 {
    struct node {
        int openBracket;
        int size;
        node(int o, int s) {
            openBracket = o;
            size = s;
        }
    };
public:
    int sol(string s) {
        if (s.size() == 0) {
            return 0;
        }

        int ans = 0;
        vector<char> c;
        if (s.at(0) == '(') {
            c.emplace_back('(');
        }
        int length = 0;
        vector<node*> back;
        for (int i = 1; i < s.length(); i++) {
            // When the current char is '( and the previous char is also '(', we need to separate it from previous length
            if (s.at(i) == '(') {
                if (s.at(i - 1) == '(' && length > 0) {
                    back.emplace_back(new node(c.size() - 1, length));
                    length = 0;
                }
                c.emplace_back('(');
            } else {
                if (c.empty()) {
                    back.clear();
                    c.clear();
                    length = 0;
                    continue;
                }
                c.pop_back();
                length += 2;
                if (!back.empty() && c.size() == back.at(back.size() - 1)->openBracket) {
                    length += back.at(back.size() - 1)->size;
                    back.pop_back();
                }
                ans = max(length, ans);
            }
        }
        return ans;
    }
};
