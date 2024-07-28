//
// Created by Kesu Peterill on 7/24/2024.
//
#include "all.h"

class leetcode71 {
public:
    string sol(string path) {
        int i=0;
        string ss="";
        stack<string> s;
        while(i!=path.length()){
            if(path[i]=='/'){
                if(!ss.empty()){
                    if(ss==".."){
                        if(!s.empty()){
                            s.pop();
                        }

                    }
                    else if(ss!="."){
                        s.push(ss);
                    }
                    ss="";
                }

            }else{
                ss+=path[i];
            }

            i++;
        }
        if(!ss.empty()){
            if(ss==".."){
                if(!s.empty()){
                    s.pop();
                }

            }
            else if(ss!="."){
                s.push(ss);
            }
        }
        cout << s.size() << endl;
        string ans;
        if(s.empty()){
            return "/";
        }
        while(!s.empty()){
            ans = "/"+s.top()+ans;
            s.pop();
        }
        return ans;
    }
};