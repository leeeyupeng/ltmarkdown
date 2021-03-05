#include"leetcode.h"

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n<2){return n;}
        vector<int> dp(n,1);
        vector<int> dpc(n,1);
        dp[0] = 1;
        int dpmax = 1;
        int counter = 1;
        for(int i = 1; i < n; i ++){
            for(int j = 0;j < i; j ++){
                if(nums[i] > nums[j]){
                    if(dp[i] < dp[j] + 1){
                        dp[i] = max(dp[i],dp[j] + 1);
                        dpc[i] = dpc[j];
                    }
                    else if(dp[i] == dp[j] + 1){
                        dpc[i]+=dpc[j];
                    }
                    else{

                    }
                }
            }

            if(dp[i]>dpmax){
                dpmax = dp[i];
                counter = dpc[i];
            }
            else if(dp[i] == dpmax){
                counter +=dpc[i];
            }
            else{

            }
        }
        return counter;
    }
};

// int main(){
//     Solution solution; 
//     vector<int> nums = {
// 1,3,5,4,7
//     };
//     int ret = solution.findNumberOfLIS(nums);

//     return 0;
// }