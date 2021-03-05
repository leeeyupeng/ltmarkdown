#include"leetcode.h"

#define CHARNUM 26
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int ret = 0;
        vector<int> dp(k+1,0);
        char c;
        k = min(n,k);
        for(int i = 0;  i < CHARNUM; i ++){
            for(int kk = 0; kk <= k;kk++){dp[kk]=0;}
            c = i + 'A';
            for(int j = 0; j < n; j ++){
                for(int kk = min(j+1,k);kk >= 0; kk --){
                    if(s[j] == c){
                        dp[kk]++;
                    }
                    else if(kk > 0){
                        dp[kk] = dp[kk-1]+1;
                    }
                    else{
                        dp[kk] = 0;
                    }
                    ret = max(ret,dp[kk]);
                }
            }
        }
        return ret;
    }
};