#include"leetcode.h"


class Solution {
private:
    int n;
    inline int findxnums(vector<int> &nums,int x){
        int i = 0,j = n;
        int mid;
        while(i<j){
            mid = (i+j)>>1;
            if(nums[mid] < x){
                i = mid+1;
            }else{
                j = mid;
            }
        }
        return n-i;
    }
public:
    int specialArray(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(),nums.end());
        int maxnums = 0;
        for(int i = 0; i <= n; i ++){
            maxnums = findxnums(nums,i);
            if(maxnums == i){
                return i;
            }
        }
        return -1;
    }
};

// int main(){
//     Solution solution;
//     vector<int> nums={

//     };
//     int ans = 0;
//     ans = solution.specialArray(nums);
//     return 0;
// }