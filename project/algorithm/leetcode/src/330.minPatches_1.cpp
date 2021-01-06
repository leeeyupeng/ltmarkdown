#include"leetcode.h"

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int numssize = nums.size();
        int index=0;
        long long x=1;
        int ret = 0;
        while((x)<=n){
            if(index<numssize){
                if(nums[index] == x){
                    x = (x<<1);
                    index++;
                }
                else if(nums[index] > x){
                    x = (x<<1);
                    ret++;
                }
                else{
                    x = max(x,(long long)nums[index] + x);
                    index++;
                }
            }
            else{
                ret++;
                x = (x<<1);
            }
        }
        return ret;
    }
};

// int main(){
//     Solution solution;
//     vector<int> nums={
//         2,2
//     };
//     int ret = solution.minPatches(nums,10000);
//     return 0;
// }