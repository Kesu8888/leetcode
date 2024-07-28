//
// Created by Kesu Peterill on 5/31/2024.
//
#include "all.h"

class leetcode29 {
public:
    int sol(int dividend, int divisor) {
        unsigned abs1 = abs(dividend);
        unsigned abs2 = abs(divisor);
        if (abs1 < abs2) {
            return 0;
        }
        int sign = 1 << 31;
        //If their sign is the same
        if ((dividend & sign) == (divisor & sign)) {
            sign = 0;
        }
        unsigned ans = 0;
        int Leftmost = 30;
        while ((abs1 >> Leftmost) == 0) {
            Leftmost --;
        }
        while (Leftmost >= 0) {
            ans = ans << 1;
            int prefix = abs1 >> Leftmost;
            if (prefix >= abs2) {
                prefix -= abs2;
                abs1 = (abs1 & (~((~0)<<Leftmost))) + (prefix << Leftmost);
                ans += 1;
            }
            Leftmost --;
        }
        if (ans == (unsigned)INT_MAX + 1) {
            return (sign == 0) ? INT_MAX : INT_MIN;
        }
        return (sign == 0) ? ans : -ans;
    }
};