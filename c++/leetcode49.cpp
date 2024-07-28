//
// Created by Kesu Peterill on 6/24/2024.
//
#include "all.h"

class leetcode49 {
public:
    vector<vector<string>> sol(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (string s : strs) {
            string sortedS = getSort(s);
            if (!m.contains(sortedS)) {
                vector<string> v;
                m.insert({sortedS, v});
            }
            m.at(sortedS).emplace_back(s);
        }
        vector<vector<string>> ans;
        for (pair<string, vector<string>> p : m) {
            ans.emplace_back(p.second);
        }
        return ans;
    }
    string getSort(string str) {
        sort(str.begin(), str.end());
        return str;
    }
};