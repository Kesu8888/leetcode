//
// Created by Kesu Peterill on 7/24/2024.
//
#include "all.h"

class leetcode205 {
public:
    bool sol(string s, string t) {
        unordered_map<char, int> mapS;
        unordered_map<char, int> mapT;

        for (int i = 0; i < s.size(); i++) {
            char schar = s.at(i);
            char tchar = t.at(i);

            if (mapS.contains(schar)) {
                if (!mapT.contains(tchar) || mapT.at(tchar) != mapS.at(schar))
                    return false;
            } else {
                if (mapT.contains(tchar))
                    return false;
                mapS.insert({schar, i});
                mapT.insert({tchar, i});
            }
        }
        return true;
    }
};