#include"leetcode.h"

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0){return 0;}
        vector<int> dp(n,INT_MIN);
        dp[0] = nums[0];
        int mmax;
        auto cmp = [](pair<int,int> &a,pair<int,int> &b){
            if(a.second == b.second){
                return a.first > b.first;
            }
            return a.second < b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
        pq.push({0,dp[0]});
        for(int i = 1; i < n; i ++){
            while(pq.top().first < i - k){
                pq.pop();
            }
            
            dp[i] = pq.top().second + nums[i];
            pq.push({i,dp[i]});
        }
        return dp[n-1];
    }
};