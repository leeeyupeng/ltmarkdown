#include"leetcode.h"

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int length = s.length();
        vector<int> counter(26,0);
        for(int i = 0; i < length; i ++){
            counter[s[i]-'a']++;
        }
        stack<char> sta;
        vector<bool> has(26,false);
        char top;
        for(int i = 0; i < length; i ++){
            if(sta.empty()){sta.push(s[i]);has[s[i]-'a'] = true;}
            else{
                if(has[s[i]-'a'] == false){
                    while(!sta.empty()){
                        top = sta.top();
                        if(top>s[i] && counter[top-'a'] > 0){
                            sta.pop();
                            has[top-'a'] = false;
                        }
                        else{
                            break;
                        }
                    }
                    if(has[s[i]-'a'] == false){
                        sta.push(s[i]);
                        has[s[i]-'a'] = true;
                    }
                }
            }
            counter[s[i]-'a']--;
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