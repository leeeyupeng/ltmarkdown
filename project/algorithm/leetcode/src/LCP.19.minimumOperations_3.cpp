#include"leetcode.h"

class Solution {
public:
    int minimumOperations(string leaves) {
        int n = leaves.length();
        unsigned int dp[3];
        dp[0]=(leaves[0]=='r'?0:1);
        dp[1]=dp[0]+(leaves[1]=='y'?0:1);
        dp[2]=dp[1]+(leaves[2]=='r'?0:1);  
        dp[0]=dp[0]+(leaves[1]=='r'?0:1);   
        dp[1]=min(dp[1],dp[0])+(leaves[2]=='y'?0:1);        
        dp[0]=dp[0]+(leaves[2]=='r'?0:1);        
        
        char r;
        for(int i = 3; i < n; i ++){      
            r = (leaves[i]=='r'?0:1); 
            dp[2] = min(dp[2],dp[1])+r;
            dp[1] = min(dp[1],dp[0])+((~r)&0x1);
            dp[0] = dp[0]+r;
        }
        return dp[2]% 1000000007ll;
    }
};

// int main(){
//     Solution s;
//     int ans = s.minimumOperations("rrryyyrryyyrr");
//     return 0;
// }