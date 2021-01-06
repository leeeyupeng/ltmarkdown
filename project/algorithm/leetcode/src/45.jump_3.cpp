#include"leetcode.h"

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxindex = 0;
        int cnt = 0;
        int cntendindex = 0;
        for(int i = 0; i < n && maxindex < n-1; i ++){
            if(i > cntendindex){
                cnt ++;
                cntendindex = maxindex;
            }
            maxindex = max(maxindex,i + nums[i]);
        }
        return cnt;
    }
};