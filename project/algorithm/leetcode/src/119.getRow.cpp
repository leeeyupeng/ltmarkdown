#include"leetcode.h"

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1);
        for(int i = 1; i <= rowIndex+1; i ++){
            ans[i-1] = 1;
            for(int j = i-2; j > 0; j --){
                ans[j] += ans[j-1];
            }
            ans[0] = 1;
        }
        return ans;
    }
};