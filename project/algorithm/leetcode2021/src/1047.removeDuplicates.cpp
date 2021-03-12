#include"leetcode.h"


class Solution {
public:
    string removeDuplicates(string S) {
        int n = S.length();
        stack<char> sta;
        for(int i = 0; i < n; i ++){
            if(sta.empty()){sta.push(S[i]);}
            else if(sta.top() == S[i]){sta.pop();}
            else{sta.push(S[i]);}
        }

        string ret;
        while(!sta.empty()){
            ret.push_back(sta.top());
            sta.pop();
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};