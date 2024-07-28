//
// Created by Kesu Peterill on 5/29/2024.
//
#include "all.h"

class leetcode88 {
public:
    void sol(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = m + n - 1;
        m = m - 1;
        n = n - 1;
        while (m >= 0 && n >= 0) {
            if (nums1.at(m) > nums2.at(n)) {
                nums1.at(last) = nums1.at(m);
                m --;
            } else {
                nums1.at(last) = nums2.at(n);
                n --;
            }
            last --;
        }
        if (m < 0) {
            while (n >= 0) {
                nums1.at(last) = nums2.at(n);
                n --;
                last --;
            }
        }
    }
};