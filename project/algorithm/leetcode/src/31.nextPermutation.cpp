#include"leetcode.h"

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-1,j = n-1;
        while(i>0){
            if(nums[i]>nums[i-1]){break;}
            i--;
        }
        if(i!=0){
            int index = i;
            while(index<n){
                if(nums[index]<=nums[i-1]){
                    swap(nums[index-1],nums[i-1]);break;
                }
                index++;
            }
            if(index == n){
                swap(nums[index-1],nums[i-1]);
            }
        }

        while(i<j){
            swap(nums[i],nums[j]);
            i++;j--;
        }
        return;
    }
};
// int main(){
//     Solution solution;
//     vector<int> nums={
//         2,4,3,2,1
//     };
//     solution.nextPermutation(nums);
//     return 0;
// }