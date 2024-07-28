//
// Created by Kesu Peterill on 7/1/2024.
//
//Better solution using built-in method
#include "all.h"

class leetcode125i {
public:
    bool sol(string s) {
        // while front and end ptrs do not cross
        // match them
        // if one is a space, move if forward

        int start = 0;
        int end = s.size()-1;

        while(start <= end) {
            if(!isalpha(s[start]) && !isdigit(s[start]))  {
                start++;
            }
            else if(!isalpha(s[end]) && !isdigit(s[end])) {
                end--;
            }
            else if(tolower(s[end]) == tolower(s[start])) {
                start++;
                end--;
            }
            else{
                return false;
            }
        }

        return true;
    }
};