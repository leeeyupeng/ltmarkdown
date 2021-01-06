#include"leetcode.h"

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n,1);
        for(int i = 0; i < n; i ++){
            for(int i = 0; i < n; i ++){
                for(int j = i-1;j >= max(0,i-d); j --){
                    if(arr[j] < arr[i]){
                        dp[i] = max(dp[i],dp[j] + 1);
                    }
                    else{
                        break;
                    }
                }
            }

            for(int i = n-1;i >=0;i --){
                for(int j = i + 1;j <= min(n-1,i+d); j ++){
                    if(arr[j] < arr[i]){
                        dp[i] = max(dp[i],dp[j] + 1);
                    }
                    else{
                        break;
                    }
                }
            }
        }

        int ret = 0;
        for(int i = 0; i < n; i ++){
            ret = max(ret,dp[i]);
        }
        return ret;
    }
};

// int main()
// {
//     vector<int> arr={
// 6,4,14,6,8,13,9,7,10,6,12
// };

//     Solution solution;
//     int ret = solution.maxJumps(arr,25);
//     return 0;
// }