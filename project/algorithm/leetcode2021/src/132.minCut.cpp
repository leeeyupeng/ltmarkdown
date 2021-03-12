#include"leetcode.h"

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<char>> ispalindrome(n,vector<char>(n,0));
        for(int i = 0; i < n; i ++){
            for(int step = 0;i - step >= 0 && i + step < n;step ++){
                if(s[i-step] != s[i+step]){
                    break;
                }
                ispalindrome[i-step][i+step] = 1;
            }

            for(int step = 0;i - step >= 0 && i + step + 1 < n;step ++){
                if(s[i-step] != s[i+step + 1]){
                    break;
                }
                ispalindrome[i-step][i+step + 1] = 1;
            }
        }

        vector<int> dp(n,n);
        dp[0] = 1;
        for(int i = 1; i < n; i ++){
            for(int j = 0;j <= i ;j ++){
                if(ispalindrome[j][i] == 1){
                    if(j == 0){
                        dp[i] = min(dp[i],1);
                    }
                    else{
                        dp[i] = min(dp[i],dp[j-1] + 1);
                    }
                }
            }
        }

        return dp[n-1];
    }
};