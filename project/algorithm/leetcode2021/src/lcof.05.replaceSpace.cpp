#include"leetcode.h"

class Solution {
public:
    string replaceSpace(string s) {
        string ret;
        int n = s.length();
        for(int i = 0; i < n; i ++){
            if(s[i] == ' '){
                ret.push_back('%');
                ret.push_back('2');
                ret.push_back('0');
            }
            else{
                ret.push_back(s[i]);
            }
        }
        return ret;
    }
};