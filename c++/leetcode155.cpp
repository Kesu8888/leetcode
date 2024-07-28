//
// Created by Kesu Peterill on 6/26/2024.
//
#include "all.h"

class MinStack {
public:
    stack<int> s;
    vector<int> min;
    MinStack() {

    }

    void push(int val) {
        if (s.empty()) {
            s.push(val);
            min.push_back(val);
            return;
        }
        if (val <= min.back()) {
            min.push_back(val);
        }
        s.push(val);
    }

    void pop() {
        if (s.top() == min.back()) {
            min.pop_back();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return min.back();
    }
};