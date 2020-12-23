#include"leetcode.h"


class Solution {
private:
    int n;
    int k;
    int ret;
    void dfs(vector<int>& nums,vector<char>& vnumsvist,vector<vector<char>>& vvist,int index,int count,int countk,int sums){
        if(count == n/k){
            int imin = n,imax = 1;
            for(int i = 1;i<=n; i ++){
                if(vvist[countk][i] == 1){
                    imin = min(imin,i);
                    imax = max(imax,i);
                }                
            }
            sums += imax - imin;
            if(countk == k-1){
                ret = min(ret,sums);
                return;
            }
            else{
                // for(int i = 1;i<=n; i ++){          
                //     vvist[i] = 0;
                // }
                dfs(nums,vnumsvist,vvist,0,0,countk+1,sums);
            }
        }

        for(int i = index; i < n; i ++){
            if(vnumsvist[i] == 0 && vvist[countk][nums[i]] == 0){
                vnumsvist[i] = 1;
                vvist[countk][nums[i]] ++;
                dfs(nums,vnumsvist,vvist,i + 1,count + 1,countk,sums);
                vnumsvist[i] = 0;
                vvist[countk][nums[i]] --;
            }
        }

    }
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        n = nums.size();
        this->k = k;
        vector<char> vnumsvist(n,0);
        vector<vector<char>> vvist(k,vector<char>(n+1,0));
        ret = INT_MAX;
        dfs(nums,vnumsvist,vvist,0,0,0,0);

        if(ret == INT_MAX){return -1;}
        return ret;
    }
};

// int main(){
//     Solution solution;
//     vector<int> nums={
// 6,3,8,1,3,1,2,2
//     };

//     int ans = solution.minimumIncompatibility(nums,2);

//     return 0;
// }