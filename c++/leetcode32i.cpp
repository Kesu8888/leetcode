//
// Created by Kesu Peterill on 6/4/2024.
//
//New method from others
#include "all.h"

class leetcode32i {
public:
    int sol(string s) {
        int i, l, c = 0, res = 0, val;
        stack<int> st;
        l = s.length();
        for (i = 0; i < l; i++) {
            if (s[i] == '(') {
                st.push(0);
            } else {
                val = 0;
                while (!st.empty() && st.top() > 0) {
                    val = val + st.top();
                    st.pop();
                }
                if (!st.empty()) {
                    st.pop();
                    val += 2;
                    st.push(val);
                }
                res = max(res, val);
            }
        }
        val=0;
        while(!st.empty())
        {
            int a=st.top();
            if(a==0)
                val=0;
            else
                val+=a;
            res=max(res,val);
            st.pop();
        }
        return res;
    }
};