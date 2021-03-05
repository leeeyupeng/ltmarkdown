#include"leetcode.h"

class Solution {
private:
    int goal;
    int ret;
    void dfs(vector<int>& nums,set<int>& us,int index,int maxindex,int value){
        if(index==maxindex){
            if(us.find(value) == us.end()){
                us.insert(value);
            }
            return;
        }
        dfs(nums,us,index+1,maxindex,value);
        dfs(nums,us,index+1,maxindex,value+nums[index]);
    }

    void dfs2(vector<int>& nums,set<int>& us,int index,int maxindex,int value){
        if(index==maxindex){
            set<int>::iterator ite = us.lower_bound(goal-value);
            if(ite!=us.end()){
                ret = min(ret,abs(goal - value-(*ite)));
            }
            if(ite!=us.begin()){
                ite--;
                ret = min(ret,abs(goal - value-(*ite)));
            }
            return;
        }
        dfs2(nums,us,index+1,maxindex,value);
        dfs2(nums,us,index+1,maxindex,value+nums[index]);
    }
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        this->goal = goal;
        ret = INT_MAX;
        int n = nums.size();
        set<int> us;
        int mid = n >>1;
        dfs(nums,us,0,mid,0);
        dfs2(nums,us,mid,n,0);
        return ret;
    }
};

// int main()
// {
//     vector<int> nums={
// -6651,401,-8998,-9269,-9167,7741,-9699

//     };
//     int goal = 30536;
//     Solution solution;
//     auto ret = solution.minAbsDifference(nums,goal);

//     return 0;
// }