//
// Created by Kesu Peterill on 7/13/2024.
//
#include "all.h"

class leetcode68 {
public:
    vector<string> sol(vector<string>& words, int maxWidth) {
        int start = 0;
        vector<string> ans;
        while (start < words.size()) {
            int width = maxWidth;
            width -= words.at(start).size();
            int i = start+1;
            int intervals = 1;
            while (i < words.size() && width >= words.at(i).size()+intervals) {
                width -= words.at(i).size();
                i ++;
                intervals ++;
            }

            if (i == words.size()) {
                break;
            }
            string s;
            if (intervals - 1 == 0) {
                s.append(words.at(start));
                autofill(s, maxWidth);
            } else {
                int odd = width % (intervals-1);
                int interval = width/(intervals-1);
                s += words.at(start);
                for (int k = start+1; k < i; k++) {
                    autofill(s, s.size() + interval);
                    if (odd > 0) {
                        s += " ";
                        odd --;
                    }
                    s += words.at(k);
                }
            }
            ans.push_back(s);
            start = i;
        }

        string s;
        s += words.at(start);
        start ++;
        for (; start < words.size(); start++) {
            s += " ";
            s += words.at(start);
        }
        autofill(s, maxWidth);
        ans.push_back(s);
        return ans;
    }

    void autofill(string& s, int maxwidth) {
        for (int i = s.size()+1; i <= maxwidth; i++) {
            s += " ";
        }
    }
};