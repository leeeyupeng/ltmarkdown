#include"leetcode.h"

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> log(k+1,0);
        log[1] = 0;log[2] = 1;
        for(int i = 3; i <= k; i ++){
            log[i] = log[i>>1] + 1;
        }
        vector<vector<int>> st(n,vector<int>(log[k] + 1,0));
        for(int i = 0; i < n; i ++){
            st[i][0] = nums[i];
        }
        for(int j = 1; j <= log[k];j ++){
            for(int i = 0; i+(1<<j) -1 < n; i ++){            
                st[i][j] = max(st[i][j-1],st[i + (1<<(j-1))][j-1]);
            }
        }
        vector<int> ans(n-k+1,0);
        for(int i = 0; i <= n-k; i ++){
            ans[i] = max(st[i][log[k]],st[i+k-1-(1<<log[k])+1][log[k]]);
        }
        return ans;
    }
};