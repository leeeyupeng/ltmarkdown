#include"leetcode.h"

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,INT_MAX);
        dp[0] = 0;
        int maxindex = 0;
        for(int i = 0; i < n; i ++){
            for(int j = maxindex - i + 1; j <= nums[i] && i+j<n;j ++){
                dp[i + j] = min(dp[i+j],dp[i] + 1);
            }
            maxindex = i + nums[i];
        }
        return dp[n-1];
    }
};