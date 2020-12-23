#include"leetcode.h"

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int> sums(n+1,0);
        sums[0] = 0;
        for(int i = 0; i < n; i ++){
            sums[i+1] = sums[i] + stones[i];
        }
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        int i,j,k;
        int temp1,temp2;
        for(k = 1;k<n; k ++){
            for(i = 1; i + k<= n;i ++){
                j = i + k;
                temp1 = sums[j] - sums[i] + min(-(sums[j-1] - sums[i]) + dp[i+1][j-1],-(sums[j] - sums[i+1]) + dp[i+2][j]);
                temp2 = sums[j-1] - sums[i-1] + min(-(sums[j-1] - sums[i]) + dp[i+1][j-1],-(sums[j-2] - sums[i-1]) + dp[i][j-2]);
                dp[i][j] = max(temp1,temp2);
            }
        }

        return dp[1][n];
    }
};

// int main(){
//     Solution solution;
//     vector<int> stones={
// 5,3,1,4,2
//     };

//     int ans = solution.stoneGameVII(stones);

//     return 0;
// }