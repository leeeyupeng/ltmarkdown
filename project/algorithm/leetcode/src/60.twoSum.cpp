#include"leetcode.h"

#define MAXPOINT 6
class Solution {
private:
    vector<int> vcount;
    int geta(int n,int k){
        int ans = 1;
        for(int i = 0; i < k; i ++){
            ans *= (n-i);
        }
        return ans;
    }
    int getc(int n,int k){
        int ans = 1;
        for(int i = 0; i < k; i ++){
            ans *= (n-i);
        }
        for(int i = 0; i < k; i ++){
            ans /= i+1;
        }
        return ans;
    }
    void dfs(int index,int n,int count){
        if(n == 0){vcount.push_back(count);return;}
        if(index == MAXPOINT - 1){count *= getc(n,n);vcount.push_back(count);return;}
        for(int i = n;i >= 0; i --){
            dfs(index+1,n-i,count * getc(n,i));
        }
    }
public:
    vector<double> twoSum(int n) {
        dfs(0,n,1);
        int all = 0;
        for(int i = 0; i < vcount.size(); i ++){
            all+=vcount[i];
        }    
        vector<double> ans(vcount.size());
        for(int i = 0; i < vcount.size(); i ++){
            ans[i] = (double)vcount[i]/(double)all;
        }
        return ans;
    }
};

// int main(){
//     Solution solution;
//     vector<double> ans = solution.twoSum(1);
//     return 0;
// }