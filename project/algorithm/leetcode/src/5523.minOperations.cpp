#include"leetcode.h"

class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<char> s;
        int n = logs.size();
        for(int i = 0; i < n; i ++)
        {
            if(logs[i].find("../")!=-1){if(!s.empty()){s.pop();}}
            else if(logs[i].find("./")!=-1){}
            else{s.push(0);}
                                    
        }
        return s.size();

    }
};