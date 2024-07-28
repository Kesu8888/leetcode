//
// Created by Kesu Peterill on 6/13/2024.
//
#include "all.h"

class leetcode42i {
    int sol(vector<int>& height) {
        int n=height.size();
        int leftmax[n];
        leftmax[0]=height[0];
        for(int i=1;i<n;i++)
        {
            leftmax[i]=max(leftmax[i-1],height[i]);
        }
        int rightmax[n];
        rightmax[n-1]=height[n-1];
        for(int i=n-2 ; i>=0 ; i--)
        {
            rightmax[i]=max(rightmax[i+1],height[i]);
        }
        int trap=0;
        for(int i=0;i<n;i++)
        {
            int water=min(rightmax[i],leftmax[i]);
            water-=height[i];
            trap+=water;
        }
        return trap;
    }
};