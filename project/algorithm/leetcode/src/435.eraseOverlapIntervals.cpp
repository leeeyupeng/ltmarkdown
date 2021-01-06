#include"leetcode.h"

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>&b){
            if(a[0]==b[0]){
                return a[1]<b[1];
            }
            return a[0]<b[0];
        });

        vector<int> dp(n,1);
        for(int i = 1; i < n; i ++){
            for(int j = 0; j < i;j ++){
                if(intervals[j][1] <= intervals[i][0]){
                    dp[i] = max(dp[i],dp[j] + 1);
                }
            }
        }
        return n - dp[n-1];
    }
};

// int main(){
//     Solution solution;
//     vector<vector<int>> intervals={
//         {1,2}, {2,3}, {3,4}, {1,3},{2,2}
//     };

//     int ret = solution.eraseOverlapIntervals(intervals);

//     return 0;
// }