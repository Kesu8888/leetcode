#include "vector"
#include "string"
#include "all.h"
using namespace std;

//
// Created by Kesu Peterill on 5/27/2024.
//
class leetcode22 {
public:
    vector<string> ans;
    vector<string> sol(int n) {
        string s;
        generate(n, 0, s, 0);
        return ans;
    }
    void generate(int left, int right, string s, int index) {
        if (left == 0 && right == 0) {
            ans.push_back(s);
            return;
        }
        if (left > 0) {
            s.push_back('(');
            generate(left - 1, right + 1, s, index + 1);
            s.pop_back();
        }
        if (right > 0) {
            s.push_back(')');
            generate(left, right - 1, s, index + 1);
        }
    }
};