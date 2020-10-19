#include"leetcode.h"

class Solution {
private:
    int n;
    int requestsnums;
    int ans = 0;

    vector<vector<int>> requests;
    vector<bool> flag;
    vector<int> nums;
    bool check(){
        for(int i = 0;i < n; i ++){
            nums[i]=0;
        }
        for(int i = 0; i < requestsnums; i ++){
            if(flag[i]==true){
                nums[requests[i][0]] --;
                nums[requests[i][1]] ++;
            }
        }
        for(int i = 0;i < n; i ++){
            if(nums[i]!=0){return false;}
        }
        return true;
    }
    void dfs(int index,int count){
        if(index == requestsnums){
            if(count > ans && check()){
                ans = count;
            }
            return;
        }
        flag[index] = true;
        dfs(index+1,count+1);
        flag[index] = false;

        if(count + (requestsnums - index - 1) > ans){
            dfs(index+1,count);
        }
    }
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        this->n = n;
        this->requests = requests;
        nums = vector<int>(this->n,0);
        this->requestsnums = requests.size();
        flag=vector<bool>(requestsnums,false);

        dfs(0,0);

        return ans;
    }
};

// int main(){
//     Solution solution;
//     vector<vector<int>> requests={
//         {0,1},{1,0},{0,1},{1,2},{2,0},{3,4}
//     };
//     int ans = solution.maximumRequests(5,requests);
//     return 0;
// }