#include"leetcode.h"

class Solution {
public:
    int minJump(vector<int>& jump) {
        int n = jump.size();
        vector<int> dp(n);
        int temp;
        for(int i = 0; i < n; i ++){dp[i]=INT_MAX;}
        dp[0]=0;
        int ans = INT_MAX;
        for(int i = 0; i < n;i ++){
            if(dp[i]==INT_MAX){break;}
            temp = i+jump[i];
            if(temp>=n){
                ans = min(ans,dp[i]+1);
            }
            else if(dp[temp]>dp[i]+1){
                dp[temp] = dp[i]+1;
                temp--;
                while(dp[temp]>=dp[i]+2){
                    dp[temp] = dp[i] + 2;
                    temp --;
                }
            }
        }
        return ans;
    }
};

// int main(){
//     vector<int> jump={
//         4,6,10,8,3,5,3,5,7,8,6,10,3,7,3,10,7,10,10,9,1,4,7,4,8,6,9,8,8,2,7,2,4,5,4,3,3,2,2,2,3,4,4,1,1,5,6,8,1,2
//     };
//     Solution solution;
//     int ans = solution.minJump(jump);
//     return 0;
// }