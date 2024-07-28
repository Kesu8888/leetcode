//
// Created by Kesu Peterill on 6/6/2024.
//
#include "all.h"

class leetcode34 {
public:
    vector<int> sol(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return vector<int>{-1, -1};
        }
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            int v = nums.at(mid);
            if (v == target) {
                int left = mid - 1;
                while (start <= left) {
                    int leftmid = (start + left) / 2;
                    if (nums.at(leftmid) == target) {
                        left = leftmid - 1;
                    } else {
                        start = leftmid + 1;
                    }
                }
                int right = mid + 1;
                while (right <= end) {
                    int rightmid = (right + end) / 2;
                    if (nums.at(rightmid) == target) {
                        right = rightmid + 1;
                    } else {
                        end = rightmid - 1;
                    }
                }
                return vector<int>{start, end};
            } else if (v < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return vector<int>{-1, -1};
    }
};