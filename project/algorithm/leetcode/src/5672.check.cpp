#include"leetcode.h"

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i<n){
            if(nums[i]<nums[(i-1+n)%n]){
                break;
            }
            i++;
        }
        int start = i;
        i++;
        while((i%n)!=start){
            if(nums[(i)%n] < nums[(i-1+n)%n]){
                return false;
            }
            i++;
        }
        return true;
    }
};

// int main(){
//     vector<int> nums={
//         2,1,3,4
//     };
//     Solution solution;
//     auto ret = solution.check(nums);
//     return 0;
// }