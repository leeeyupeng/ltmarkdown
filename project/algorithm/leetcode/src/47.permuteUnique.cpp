#include "leetcode.h"

class Solution {
private:
    int n;
    int *v;
    bool *flag;
    vector<vector<int>> ans;
    void dfs(vector<int>& nums,int count){
        if(count == n){
            vector<int> temp(n);
            for(int i = 0; i < n; i ++){
                temp[i] = v[i];
            }
            ans.push_back(temp);
        }
        for(int i = 0; i < n;i ++){
            if(flag[i] == false){
                //if(i>0 && nums[i-1]==nums[i] && (count == 0 || v[count-1]!=nums[i])){continue;}
                if(i>0&&nums[i-1]==nums[i]&&flag[i-1]==false){continue;}
                flag[i] = true;
                v[count]=nums[i];
                dfs(nums,count+1);
                flag[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        n = nums.size();
        v = new int[n];
        flag=new bool[n];
        for(int i = 0; i < n; i ++){flag[i] = false;}
        dfs(nums,0);
        delete[] v;
        delete[] flag;

        return ans;
    }
};

// int main(){
//     vector<int> nums={
//         5,1,1,2
//     };
//     Solution solution;
//     vector<vector<int>> ans = solution.permuteUnique(nums);
//     return 0;
// }