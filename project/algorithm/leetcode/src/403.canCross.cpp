#include"leetcode.h"

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<char>> dp(n,vector<char>(n+1,0));
        dp[0][0] = 1;
        for(int i = 1; i < n; i ++){
            for(int j = 0; j < i; j ++){
                if(stones[i] - stones[j] < n && dp[i][stones[i] - stones[j]] == 0){
                    dp[i][stones[i] - stones[j]] |= dp[j][stones[i] - stones[j]];
                    if(stones[i] - stones[j] - 1 >= 0){
                        dp[i][stones[i] - stones[j]] |= dp[j][stones[i] - stones[j] - 1];
                    }
                    if(stones[i] - stones[j] + 1 < n){
                        dp[i][stones[i] - stones[j]] |= dp[j][stones[i] - stones[j] + 1];
                    }
                }
            }
        }
        char ret = 0;
        for(int i = 0; i < n; i ++){
            ret |= dp[n-1][i];
        }
        return ret == 1;
    }
};