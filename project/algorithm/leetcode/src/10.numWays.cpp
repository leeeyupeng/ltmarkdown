#include"leetcode.h"

class Solution {
public:
    int numWays(int n) {
        if(n==0){return 1;}
        else if(n==1){return 1;}
        else if(n==2){return 2;}
        unsigned int *dp=new unsigned int[n+1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n;i ++){
            dp[i] = dp[i-1] + dp[i-2];
            dp[i]%=1000000007;
        }
        return dp[n];
    }
};