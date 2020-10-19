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
    void dfs(int index,int n,int count,int points){
        if(n == 0){vcount[points]+=count;return;}
        if(index == MAXPOINT - 1){count *= getc(n,n);vcount[points+n*(index+1)]+=count;return;}
        for(int i = n;i >= 0; i --){
            dfs(index+1,n-i,count * getc(n,i),points + i * (index+1));
        }
    }
public:
    vector<double> twoSum(int n) {
        vcount=vector<int>(MAXPOINT * n + 1,0);
        dfs(0,n,1,0);
        int all = pow(MAXPOINT,n);
        vector<double> ans;
        for(int i = 0; i < vcount.size(); i ++){
            if(vcount[i]!=0){
                ans.push_back((double)vcount[i]/(double)all);
            }
        }
        return ans;
    }
};

// int main(){
//     Solution solution;
//     vector<double> ans = solution.twoSum(2);
//     return 0;
// }