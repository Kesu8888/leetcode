//
// Created by Kesu Peterill on 6/29/2024.
//
#include "all.h"

class leetcode57 {
public:
    vector<vector<int>> sol(vector<vector<int>>& intervals, vector<int>& newInterval) {
       int min = newInterval[0];
       int max = newInterval[1];
       double minPos = getPos(min, intervals);
       double maxPos = getPos(max, intervals);
       if (maxPos == minPos) {
           if (minPos != (int)minPos) {
               intervals.insert(intervals.begin()+(minPos+1), {min, max});
           }
           return intervals;
       }
       int left, right;
       if (minPos != (int)minPos) {
           minPos = (int)(minPos+1);
           left = min;
       } else {
           left = intervals.at(minPos).at(0);
       }
       if (maxPos > (int)maxPos) {
           maxPos = (int)maxPos;
           right = max;
       } else {
           right = intervals.at(maxPos).at(1);
       }
       for (int i = 0; i <= (maxPos-minPos); i++) {
           intervals.erase(intervals.begin()+minPos);
       }
       intervals.insert(intervals.begin()+minPos, {left, right});
       return intervals;
    }
    double getPos(int num, vector<vector<int>>& intervals) {
        int left = 0;
        int right = intervals.size()-1;
        while (left <= right) {
            int mid = (left+right)/2;
            vector<int> interval = intervals.at(mid);
            if (num < interval.at(0)) {
                right = mid-1;
            } else if (num > interval.at(1)) {
                left = mid+1;
            } else {
                return mid;
            }
        }
        return min(left, right)+0.5;
    }
};