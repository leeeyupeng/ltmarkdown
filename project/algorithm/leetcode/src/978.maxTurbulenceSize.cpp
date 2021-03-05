#include"leetcode.h"

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if(n<=1){return n;}
        vector<int> dp1(n,1);
        vector<int> dp2(n,1);
        int ret = 1;
        for(int i = 1; i < n; i ++){
            if(arr[i]<arr[i-1]){
                dp2[i] = max(dp2[i],dp1[i-1] + 1);
            }
            else if(arr[i]>arr[i-1]){
                dp1[i] = max(dp1[i],dp2[i-1] + 1);
            }
            ret = max(ret,dp1[i]);
            ret = max(ret,dp2[i]);
        }
        return ret;
    }
};