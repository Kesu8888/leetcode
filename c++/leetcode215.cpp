//
// Created by Kesu Peterill on 7/20/2024.
//
#include "all.h"

class leetcode215 {
public:
    int sol(vector<int>& nums, int k) {
        int result;
        if (k < nums.size()/2) {
            priority_queue<int> maxHeap;
            for (int i : nums) {
                maxHeap.push(i);
            }
            k = k-1;
            while (k >= 0) {
                result = maxHeap.top();
                maxHeap.pop();
                k -= 1;
            }
        } else {
            priority_queue<int, vector<int>, greater<>> minHeap;
            for (int i : nums) {
                minHeap.push(i);
            }
            k = nums.size()-k;
            while (k >= 0) {
                result = minHeap.top();
                minHeap.pop();
                k -= 1;
            }
        }
        return result;
    }
};