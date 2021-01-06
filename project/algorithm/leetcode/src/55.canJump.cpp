#include"leetcode.h"

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxindex = 0;
        for(int i = 0; i < n; i ++){
            if(i<=maxindex){
                maxindex = max(maxindex,i + nums[i]);
            }
            else{
                break;
            }
        }
        return maxindex>= n-1;
    }
};