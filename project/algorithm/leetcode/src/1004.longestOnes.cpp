#include"leetcode.h"

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int n = A.size();
        if(n==0){return 0;}
        int ret = 0;
        vector<int> dp(K+1,1);
        dp[0]=A[0]==1?1:0;
        for(int i = 1; i < n; i ++){
            for(int j = min(i+1,K);j>0;j--){                
                if(A[i]==1){
                    dp[j] = max(dp[j] + 1,dp[j-1] + 1);
                }
                else{
                    dp[j] = dp[j-1] + 1;
                }
            }
            if(A[i]==1){
                dp[0] = dp[0] + (A[i]==1?1:0);
            }
            else{
                dp[0] = 0;
            }
            ret = max(ret,dp[min(i+1,K)]);
        }
        return ret;
    }
};

// int main(){
//     Solution solution;
//     vector<int> A={
// 0,0,0,1
//     };

//     int K = 4;
//     auto ret = solution.longestOnes(A,K);
//     return 0;
// }