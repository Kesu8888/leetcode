//
// Created by Kesu Peterill on 6/27/2024.
//
#include "all.h"

class leetcode51 {
public:
    vector<vector<string>> ans;
    int size;
    vector<string> Template;
    vector<vector<string>> sol(int n) {
        size = n;
        string s;
        for (int i = 0; i < n; i++) {
            s += ".";
        }
        for (int i = 0; i < n; i++) {
            Template.push_back(s);
        }
        unordered_map<int, int> queens;
        placing(queens);
        return ans;
    }

    void placing(unordered_map<int, int>& queens) {
        if (queens.size() == size) {
            for (pair<int, int> p : queens) {
                Template.at(p.first).at(p.second%size) = 'Q';
            }
            ans.emplace_back(Template);
            for (pair<int, int> p : queens) {
                Template.at(p.first).at(p.second%size) = '.';
            }
            return;
        }
        for (int i = 0; i < size; i++) {
            if (!queens.contains(i)) {
                int currentPos = i*size + queens.size();
                bool attack = false;
                for (pair<int, int> p : queens) {
                    if (currentPos < p.second) {
                        if ((p.second-currentPos) % (size-1) == 0) {
                            attack = true;
                            break;
                        }
                    } else {
                        if ((currentPos-p.second) % (size+1) == 0) {
                            attack = true;
                            break;
                        }
                    }
                }
                if (!attack) {
                    queens.insert({i, currentPos});
                    placing(queens);
                    queens.erase(i);
                }
            }
        }
    }

};