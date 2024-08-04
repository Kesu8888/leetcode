//
// Created by Kesu Peterill on 8/1/2024.
//
#include "all.h"

class leetcode76 {
public:
    string sol(string s, string t) {
        if (s.size() < t.size())
            return "";

        //Construct a map containing all the elements in t
        unordered_map<char, int> list;
        for (char c : t)
            addElement(list, c);
        int table[124]{};

        int i = 0;
        bool comp;
        for (pair<char, int> p : list) {
            comp = false;
            if (table[p.first] >= p.second) {
                comp = true;
                continue;
            }
            while (i < s.size())  {
                table[s.at(i)] ++;
                i++;
                if (table[p.first] >= p.second) {
                    comp = true;
                    break;
                }
            }
            if (!comp)
                return "";
        }
        pair<int, int> result = {0, i};
        int left = 0;

        while (i <= s.size()) {
            char c = s.at(left);
            left++;
            if (list.contains(c)) {
                table[c] --;
                if (table[c] < list.at(c)) {
                    comp = false;
                    while (i < s.size()) {
                        table[s.at(i)]++;
                        if (s.at(i) == c) {
                            i++;
                            comp = true;
                            break;
                        }
                        i++;
                    }
                }
            }
            if (!comp)
                return s.substr(result.first, result.second);
            if (i-left < result.second)
                result = {left, i-left};
        }
        return s.substr(result.first, result.second);
    }

    void addElement(unordered_map<char, int>& list, char c) {
        if (list.contains(c)) {
            list.at(c) += 1;
        } else {
            list.insert({c, 1});
        }
    }
};