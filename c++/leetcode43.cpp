//
// Created by Kesu Peterill on 6/14/2024.
//
#include "all.h"

class leetcode43 {
public:
    string sol(string num1, string num2) {
        vector<unsigned long long> n1, n2;
        int limit = (num1.size() + num2.size() < 18) ? 19 : 8;
        unsigned long v = 0;

        int i = 0;
        int p = 0;
        getIntArray(num1, n1, limit);
        getIntArray(num2, n2, limit);
        unsigned long long max = pow(10, limit);
        vector<unsigned long long> ans;
        unsigned long long remaining = 0;
        for (i = 0; i < n1.size(); i++) {
            for (int j = 0; j < n2.size(); j++) {
                if (i + j >= ans.size()) {
                    ans.emplace_back(0);
                }
                unsigned long long temp = ans.at(i + j) + n1[i] * n2[j] + remaining;
                remaining = temp/max;
                ans.at(i + j) = temp - remaining*max;
            }
            if (remaining > 0) {
                if (i + n2.size() >= ans.size()) {
                    ans.emplace_back(0);
                }
                unsigned long long temp = ans.at(i + n2.size()) + remaining;
                remaining = temp/max;
                ans.at(i + n2.size()) = temp - remaining*max;
            }
        }
        string returnS;
        returnS += to_string(ans.at(ans.size() - 1));
        for (i = ans.size() - 2; i >= 0; i--) {
            string s = to_string(ans.at(i));
            if (s.size() % limit != 0) {
                string front;
                for (int k = s.size(); k%limit != 0; k++) {
                    front += '0';
                }
                s = front + s;
            }
            returnS += s;
        }
        return returnS;
    }
    void getIntArray(string& num, vector<unsigned long long>& n, int limit) {
        int i = 0, p = 0;
        unsigned long long v = 0;
        for (i = num.size() - 1; i >= 0; i--) {
            v += (num.at(i) - '0') * pow(10, p);
            p ++;
            if (p == limit || i == 0) {
                n.emplace_back(v);
                v = 0;
                p = 0;
            }
        }
    }
};