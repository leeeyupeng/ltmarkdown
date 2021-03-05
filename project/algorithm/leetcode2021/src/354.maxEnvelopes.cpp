#include"leetcode.h"

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if(n==0){return 0;}
        sort(envelopes.begin(),envelopes.end(),[](vector<int>&a,vector<int>&b){
            if(a[0] == b[0]){return a[1] < b[1];}
            return a[0] < b[0];
        });

        int ret = 1;
        vector<int> dp(n,1);
        for(int i = 1;i<n; i ++){
            for(int j = i-1; j >= 0; j --){
                if(envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]){
                    dp[i] = max(dp[i],dp[j] +1);
                }
            }
            ret = max(ret,dp[i]);
        }
        return ret;
    }
};