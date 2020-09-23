#include"leetcode.h"

class Solution {
private:
    int n;
public:
    bool stoneGame(vector<int>& piles) {
        n = piles.size();
        vector<vector<int>> dp(n,vector<int>(n));
        vector<int> sums(n);
        for(int i = 0; i < n; i ++){
            dp[i][i] = piles[i];
        }
        sums[0]=piles[0];
        for(int i = 1;i<n; i++){sums[i]=sums[i-1]+piles[i];}
        int k,i,j;
        for(k = 1;k<n;k++){
            for(i = 0; i < n-k; i ++){
                j = i+k;
                dp[i][j]=(sums[j] - (i>0?sums[i-1]:0)) - min(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][n-1]>(sums[n-1]>>1);
    }
};

// int main(){
//     Solution solution;
//     vector<int> piles={
//         5,3,4,5
//     };
//     bool ans = solution.stoneGame(piles);
//     return 0;
// }