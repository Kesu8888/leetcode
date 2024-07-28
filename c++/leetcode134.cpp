//
// Created by Kesu Peterill on 7/11/2024.
//
#include "all.h"

class leetcode134 {
public:
    /*int sol(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        if (gas.size() == 1) {
            return gas[0] == cost[0] ? 0 : -1;
        }

        int nogas = gas.at(0) - cost.at(0);
        int start = 0;
        int end = 0;
        int NO = 1;

        while (NO != gas.size()) {
            if (nogas >= 0) {
                end ++;
                nogas += gas.at(end) - cost.at(end);
            } else {
                start --;
                if (start < 0)
                    start = size-1;
                nogas += gas.at(start) - cost.at(start);
            }
            NO ++;
        }
        if (nogas >= 0) {
            return start;
        }
        return -1;
    }*/
    int sol(vector<int>& gas, vector<int>& cost) {
        int sum1=0;
        int sum2=0;
        //Get the total gas and total cost
        for(int i=0;i<gas.size();i++)
        {
            sum1=sum1+gas[i];
            sum2=sum2+cost[i];
        }
        if(sum2>sum1)
        {
            return -1;
        }
        //
        int tank=0;
        int ans=0;
        for(int i=0;i<gas.size();i++)
        {
            tank=tank+gas[i]-cost[i];
            if(tank<0)
            {
                // Set the ans to the station with highest gas
                tank=0;
                ans=i+1;
            }
        }
        return ans;
    }
};