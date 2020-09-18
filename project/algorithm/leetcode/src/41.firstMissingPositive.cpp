#include"leetcode.h"

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n;i ++){
            if(nums[i]<=0){nums[i] = n+1;}
            else if(nums[i]>n+1){nums[i] = n+1;}
        }
        int value,index;
        for(int i = 0; i < n;i++){
            value = nums[i]>0?nums[i]:-nums[i];
            if(value<=n){
                index = value-1;
                if(nums[index]>0){nums[index] = -nums[index];}
            }
        }
        for(int i = 0; i < n; i++){
            if(nums[i]>0){
                return i + 1;
            }
        }
        return n+1;
    }
};

// int main(){
//     Solution solution;
//     vector<int> nums={
// 3,4,-1,1
//     };
//     int ans = solution.firstMissingPositive(nums);
//     return 0;
// }