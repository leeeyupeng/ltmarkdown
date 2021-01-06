#include"leetcode.h"

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < n; i ++){
            for(int j = min(nums[i],n-i-1); j>0;j --){
                if(dp[i+j] > dp[i] + 1){
                    dp[i+j] = dp[i] + 1;
                }
                else{
                    break;
                }
            }
        }
        return dp[n-1];
    }
};