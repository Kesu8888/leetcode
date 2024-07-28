//
// Created by Kesu Peterill on 7/10/2024.
//
#include "all.h"

class leetcode202 {
public:
    bool sol(int n) {
        int slow = n;
        int fast = n;

        do
        {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        } while (slow != 1 && fast != 1 && slow != fast);

        return slow == 1 || fast == 1;
    }
    int getNext(int n)
    {
        int newNum = 0;
        while (n != 0)
        {
            newNum += (n % 10) * (n % 10);
            n /= 10;
        }

        return newNum;
    }
};