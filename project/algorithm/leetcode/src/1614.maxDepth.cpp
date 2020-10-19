#include"leetcode.h"

class Solution {
public:
    int maxDepth(string s) {
        if(s.empty()){return 0;}
        int ans = 0;
        int depth = 0;
        for(int i = 0; i < s.length(); i ++){
            if(s[i]=='('){
                depth++;
            }
            else if(s[i] == ')'){
                ans = max(ans,depth);
                depth--;
            }
        }
        return ans;
    }
};