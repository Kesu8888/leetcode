//
// Created by Kesu Peterill on 7/20/2024.
//
#include "all.h"

//This method reduces the (n+k)(logn) to nlogn, thus it has better runtime than my method
class leetcode215i {
public:
    int sol(vector<int>& nums, int k) {
        priority_queue<int , vector<int> , greater<int>> pq; //will arrange in min heap

        int n = nums.size();

        for(int i=0; i<k; i++){
            pq.push(nums[i]);
        }

        for(int i=k ; i<n; i++){
            if(nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }

        return pq.top();
    }
};