#include"leetcode.h"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==0){return 0;}
        vector<int> tails(n+1,0);
        tails[1] = nums[0];
        int ans = 1;
        int i,j;
        int ii,jj,mid;
        for(i = 1; i < n; i ++){
            ii = 1;jj = ans + 1;
            while(ii<jj){
                mid = (ii+jj)>>1;
                if(tails[mid] < nums[i]){
                    ii = mid + 1;
                }
                else{
                    jj = mid;
                }
            }
            tails[jj] = nums[i];
            ans = max(ans,jj);
        }
        return ans;
    }
};