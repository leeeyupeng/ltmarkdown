#include"leetcode.h"

#define MAXNUMS (n+4000+2)
#define OFFSETNUMS (2000+1)
#define MAXLONGLONG 18446744073709551615ll
class Solution {
public:
    vector<int> numsGame(vector<int>& nums) {
        int n = nums.size();
        vector<unsigned long long> *dp = new vector<unsigned long long>(MAXNUMS);
        vector<unsigned long long> *dpnext = new vector<unsigned long long>(MAXNUMS);
        vector<int> ans(n);        
        ans[0] = 0;
        int index = 1;
        unsigned long long minstep=MAXLONGLONG;
        int tempvalue;
        unsigned long long tempans;
        for(int i = 0; i < MAXNUMS; i ++){
            tempvalue = i - OFFSETNUMS;
            (*dp)[i] = abs(nums[0]-tempvalue);
        }
        while(index<n){
            minstep=MAXLONGLONG;
            for(int i = index; i < MAXNUMS; i ++){                
                tempvalue = i - OFFSETNUMS;
                (*dpnext)[i] = (*dp)[i-1] + abs(nums[index] - tempvalue);
                minstep = min(minstep,(*dpnext)[i]);
            }            
            ans[index] = (int)(minstep%1000000007ll);
            index++;
            swap(dp,dpnext);
        }
        return ans;
    }
};

// int main(){
//     vector<int> nums;
//     for(int i = 0; i < 100000; i ++){
//         nums.push_back(rand()%100);
//     }
//     nums = {3,4,5,1,6,7};
//     Solution solution;
//     vector<int> ans = solution.numsGame(nums);
//     return 0;
// }