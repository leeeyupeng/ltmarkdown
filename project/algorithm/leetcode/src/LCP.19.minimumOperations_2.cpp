#include"leetcode.h"

class Solution {
public:
    int minimumOperations(string leaves) {
        int n = leaves.length();
        vector<long long> dp[3]={vector<long long>(n),vector<long long>(n),vector<long long>(n)};
        dp[0][0]=(leaves[0]=='r'?0:1);
        dp[0][1]=dp[0][0]+(leaves[1]=='r'?0:1);
        dp[0][2]=dp[0][1]+(leaves[2]=='r'?0:1);
        dp[1][1]=dp[0][0]+(leaves[1]=='y'?0:1);
        dp[1][2]=min(dp[1][1],dp[0][1])+(leaves[2]=='y'?0:1);
        dp[2][2]=dp[1][1]+(leaves[2]=='r'?0:1);
        for(int i = 3; i < n; i ++){
            dp[0][i] = dp[0][i-1]+(leaves[i]=='r'?0:1);
            dp[1][i] = min(dp[1][i-1],dp[0][i-1])+(leaves[i]=='y'?0:1);
            dp[2][i] = min(dp[2][i-1],dp[1][i-1])+(leaves[i]=='r'?0:1);
        }
        return dp[2][n-1] % 1000000007ll;
    }
};

// int main(){
//     Solution s;
//     int ans = s.minimumOperations("rrryyyrryyyrr");
//     return 0;
// }