#include"leetcode.h"

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i,j;
        int j1,j2;
        int mid;
        int ret=0;
        vector<char> visit(n,0);
        for(i = 0; i<n&&nums[i] + nums[i] <= k; i ++){
            if(visit[i] == 1){continue;}
            j1= i+1;j2 = n;
            while(j1<j2){
                mid = (j1+j2)>>1;
                if(nums[i] + nums[mid] < k){
                    j1 = mid+1;
                }
                else{
                    j2 = mid;
                }
            }

            j = j1;
            while(j<n&&visit[j] == 1){j++;}
            if(j == n){continue;}
            if(nums[i] + nums[j] > k){
                continue;
            }
            else{
                ret ++;
                visit[j] = 1;
            }
        }
        return ret;
    }
};

// int main(){
//     Solution solution;
//     vector<int> nums = {
//         3,1,3,4,3
//     };
//     int ans = solution.maxOperations(nums,6);
//     return 0;
// }