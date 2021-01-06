#include"leetcode.h"

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        vector<bool> dp(n+1,false);
        dp[0] = true;
        for(int i = 0; i < nums.size(); i ++){
            for(int j = n;j >= nums[i]; j --){
                dp[j] = dp[j] | dp[j-nums[i]];
            }
        }

        int ret = 0;
        for(int i = 1; i <= n; i ++){
            if(dp[i] == false)
            {
                ret++;
                 for(int j = n;j >= i; j --){
                    dp[j] = dp[j] | dp[j-i];
                }
            }
        }

        return ret;
    }
};