#include"leetcode.h"

class Solution {
private:
    int m,n,k;
    int ret;
    bool checkgrid(int i,int j){
        int ret = 0;
        while(i!=0){
            ret+=i%10;
            i/=10;
        }
        while(j!=0){
            ret+=j%10;
            j/=10;
        }
        return ret<=k;
    }
    void _dfs(vector<vector<char>>& dp,int i,int j){
        if(i<0 || j < 0 || i >= m || j >= n){return;}
        if(dp[i][j] == 0 && checkgrid(i,j)){
            ret++;
            dp[i][j] = 1;
            _dfs(dp,i - 1,j);
            _dfs(dp,i + 1,j);
            _dfs(dp,i,j - 1);
            _dfs(dp,i,j + 1);
        }
    }
public:
    int movingCount(int m, int n, int k) {
        this->m = m;
        this->n = n;
        this->k = k;
        this->ret = 0;
        vector<vector<char>> dp(m,vector<char>(n,0));
        _dfs(dp,0,0);
        return this->ret;

    }
};