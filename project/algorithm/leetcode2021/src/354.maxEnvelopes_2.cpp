#include"leetcode.h"

//最长递增子序列 基于二分查找的动态规划
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if(n==0){return 0;}
        sort(envelopes.begin(),envelopes.end(),[](vector<int>&a,vector<int>&b){
            if(a[0] == b[0]){return a[1] > b[1];}
            return a[0] < b[0];
        });

        int ret = 1;
        vector<int> tails(n+1,0);
        tails[1] = envelopes[0][1];
        int j;
        int ii,jj;
        int mid;
        for(int i = 1;i<n; i ++){
            ii = 0;jj = ret+1;
            while(ii<jj){
                mid = (ii+jj)>>1;
                if(tails[mid] < envelopes[i][1]){ii = mid+1;}
                else{jj = mid;}
            }
            j = jj - 1;
            tails[j+1] = envelopes[i][1];
            ret = max(ret,j+1);
        }
        return ret;
    }
};