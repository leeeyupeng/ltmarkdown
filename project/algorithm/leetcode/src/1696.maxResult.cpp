#include"leetcode.h"

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0){return 0;}
        vector<int> dp(n,INT_MIN);
        dp[0] = nums[0];
        int mmax;
        priority_queue<int> pq;
        priority_queue<int> pq2;
        pq.push(dp[0]);
        for(int i = 1; i < n; i ++){
            dp[i] = max(dp[i],pq.top() + nums[i]);
            pq.push(dp[i]);
            if(i-k>=0){
                pq2.push(dp[i-k]);
            }
            while(!pq2.empty() && !pq.empty() && pq.top() == pq2.top()){
                pq.pop();
                pq2.pop();
            }
        }
        return dp[n-1];
    }
};