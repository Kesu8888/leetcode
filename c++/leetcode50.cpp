//
// Created by Kesu Peterill on 6/24/2024.
//
#include "all.h"

class leetcode50 {
public:
    double sol(double x, int n) {
        if (n == 0 || x == 1) {
            return 1;
        }
        double pow = 1;
        x = (n < 0) ? 1/x : x;
        n = abs(n);
        while(n != 0){
            if((n & 1) != 0) {
                pow *= x;
            }
            x *= x;
            n = n >> 1;
        }
        return pow;
    }
};