#include"leetcode.h"

#define MAX 100
class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        vector<int> dp(MAX*MAX*MAX*MAX + 1,0);
        int key;
        int w,l,h;
        int wlhmin,wlhmax;
        for(int k = 0; k < n; k ++){
            wlhmin= min(cuboids[k][0],min(cuboids[k][1],cuboids[k][2]));
            wlhmax= max(cuboids[k][0],max(cuboids[k][1],cuboids[k][2]));
            for(int minw = 0;minw <= wlhmax; minw++){
                for(int minl = 0; minl <= wlhmax; minl ++){
                    for(int maxw = MAX; maxw > max(minw,wlhmin); maxw--){
                        for(int maxl = MAX; maxl > max(minl,wlhmin); maxl --){
                            key = minw * MAX * MAX * MAX + minl * MAX * MAX + maxw * MAX + maxl;
                            w = 0;l = 1;h = 2;
                            if(cuboids[k][w]>=minw&&cuboids[k][l]>=minl && cuboids[k][w]<=maxw && cuboids[k][l]<=maxl){
                                dp[key] = max(dp[key],dp[minw * MAX * MAX * MAX + minl * MAX * MAX + cuboids[k][w] * MAX + cuboids[k][l]]
                                +cuboids[k][h] + dp[cuboids[k][w] * MAX * MAX * MAX + cuboids[k][l] * MAX * MAX + maxw * MAX + maxl]);
                            }
                            w = 1;l = 0;h = 2;
                            if(cuboids[k][w]>=minw&&cuboids[k][l]>=minl && cuboids[k][w]<=maxw && cuboids[k][l]<=maxl){
                                dp[key] = max(dp[key],dp[minw * MAX * MAX * MAX + minl * MAX * MAX + cuboids[k][w] * MAX + cuboids[k][l]]
                                +cuboids[k][h] + dp[cuboids[k][w] * MAX * MAX * MAX + cuboids[k][l] * MAX * MAX + maxw * MAX + maxl]);
                            }
                            w = 0;l = 2;h = 1;
                            if(cuboids[k][w]>=minw&&cuboids[k][l]>=minl && cuboids[k][w]<=maxw && cuboids[k][l]<=maxl){
                                dp[key] = max(dp[key],dp[minw * MAX * MAX * MAX + minl * MAX * MAX + cuboids[k][w] * MAX + cuboids[k][l]]
                                +cuboids[k][h] + dp[cuboids[k][w] * MAX * MAX * MAX + cuboids[k][l] * MAX * MAX + maxw * MAX + maxl]);
                            }
                            w = 2;l = 0;h = 1;
                            if(cuboids[k][w]>=minw&&cuboids[k][l]>=minl && cuboids[k][w]<=maxw && cuboids[k][l]<=maxl){
                                dp[key] = max(dp[key],dp[minw * MAX * MAX * MAX + minl * MAX * MAX + cuboids[k][w] * MAX + cuboids[k][l]]
                                +cuboids[k][h] + dp[cuboids[k][w] * MAX * MAX * MAX + cuboids[k][l] * MAX * MAX + maxw * MAX + maxl]);
                            }
                            w = 1;l = 2;h = 0;
                            if(cuboids[k][w]>=minw&&cuboids[k][l]>=minl && cuboids[k][w]<=maxw && cuboids[k][l]<=maxl){
                                dp[key] = max(dp[key],dp[minw * MAX * MAX * MAX + minl * MAX * MAX + cuboids[k][w] * MAX + cuboids[k][l]]
                                +cuboids[k][h] + dp[cuboids[k][w] * MAX * MAX * MAX + cuboids[k][l] * MAX * MAX + maxw * MAX + maxl]);
                            }
                            w = 2;l = 1;h = 0;
                            if(cuboids[k][w]>=minw&&cuboids[k][l]>=minl && cuboids[k][w]<=maxw && cuboids[k][l]<=maxl){
                                dp[key] = max(dp[key],dp[minw * MAX * MAX * MAX + minl * MAX * MAX + cuboids[k][w] * MAX + cuboids[k][l]]
                                +cuboids[k][h] + dp[cuboids[k][w] * MAX * MAX * MAX + cuboids[k][l] * MAX * MAX + maxw * MAX + maxl]);
                            }
                        }
                    }
                }
            }
        }
        return dp[0 * MAX * MAX * MAX + 0 * MAX * MAX + 100 * MAX + 100];
    }
};

// int main(){
//     vector<vector<int>> cuboids={
// {50,45,20},{95,37,53},{45,23,12}
//     };
//     Solution solution;
//     int ret = solution.maxHeight(cuboids);
//     return 0;
// }