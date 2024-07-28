//
// Created by Kesu Peterill on 7/20/2024.
//
#include "all.h"

class leetcode502{
public:
    int sol(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> combo;
        for (int i = 0; i < profits.size(); i++) {
            combo.emplace_back(capital[i], profits[i]);
        }
        sort(combo.begin(), combo.end(), greater<>());
        priority_queue<int> maxHeap;
        while (k > 0) {
            insert(maxHeap, w, combo);
            if (maxHeap.empty()) {
                break;
            }
            w += maxHeap.top();
            maxHeap.pop();
            k --;
        }
        return w;
    }

    static void insert(priority_queue<int>& maxHeap, int capital, vector<pair<int, int>>& combo) {
        while (!combo.empty()) {
            pair<int,int> p = combo.back();
            if (p.first > capital) {
                break;
            }
            maxHeap.push(p.second);
            combo.pop_back();
        }
    }
};