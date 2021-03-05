#include"leetcode.h"

class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        for(int k = 0; k < n; k ++){
            for(int i = 0; i < 3; i ++){
                for(int j = 0; j < 3-i-1;j ++){
                    if(cuboids[k][j]>cuboids[k][j+1]){
                        swap(cuboids[k][j],cuboids[k][j+1]);
                    }
                }
            }
        }

        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i = 0; i < n; i++){
            dp[i][i] = cuboids[i][2];
        }
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n;j ++){
                if(i!=j){
                    if(cuboids[i][0] == cuboids[j][0] && cuboids[i][1] == cuboids[j][1] && cuboids[i][2] == cuboids[j][2]){
                        if(i<j){
                            dp[i][j] = dp[i][i] + dp[j][j];
                        }
                    }
                    else if(cuboids[i][0] <= cuboids[j][0] && cuboids[i][1] <= cuboids[j][1] && cuboids[i][2] <= cuboids[j][2]){
                        dp[i][j] = dp[i][i] + dp[j][j];
                    }
                }
            }
        }
        for(int k = 0; k < n; k ++){
            for(int i = 0; i < n; i ++){
                for(int j = 0; j < n;j ++){               
                    if(i != j && i != k && j != k){
                        if(cuboids[i][0] <= cuboids[k][0] && cuboids[i][1] <= cuboids[k][1] && cuboids[i][2] <= cuboids[k][2]
                        &&cuboids[k][0] <= cuboids[j][0]&&cuboids[k][1] <= cuboids[j][1]&&cuboids[k][2] <= cuboids[j][2])
                        {
                            if(dp[i][k]!=0 && dp[k][j]!=0){
                                dp[i][j] = max(dp[i][j],dp[i][k] + dp[k][j] - dp[k][k]);
                            }
                        }
                    }
                }
            }
        }
        int ret = 0;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n;j ++){
                ret = max(ret,dp[i][j]);
            }
        }
        return ret;
    }
};

// int main(){
//     vector<vector<int>> cuboids={
// //        {50,45,20},{95,37,53},{45,23,12}
// //{7,11,17},{7,17,11},{11,7,17},{11,17,7},{17,7,11},{17,11,7}
// {13,82,63},{86,27,31},{96,75,81},{6,77,53},{86,59,83},{68,76,7},{86,40,40},{72,20,13},{6,63,31},{69,87,40},{88,1,33},{88,89,60},{84,10,2},{90,61,38},{13,95,28},{5,24,48},{18,59,72},{65,80,78},{26,64,45},{16,45,29},{83,94,86},{21,98,7},{3,3,88},{60,45,52},{25,78,32},{48,65,65},{78,18,93},{71,61,24},{41,89,15},{44,26,70},{62,85,1},{12,63,41},{5,78,9},{65,75,22},{74,12,54},{84,14,47},{54,55,91},{43,69,46},{39,55,21},{31,80,28},{5,52,82},{70,79,38},{48,90,70},{35,23,62},{66,80,62},{6,85,35},{88,70,79},{62,49,37},{57,59,95},{28,50,96},{54,10,49},{38,56,25},{40,52,54},{7,65,76},{100,9,26},{68,77,83},{73,58,81},{86,60,72},{1,17,17},{90,74,5},{87,100,12},{74,63,48},{27,2,79},{38,30,49},{65,32,38},{30,83,11}
//     };
//     // cuboids.clear();
//     // for(int i = 0; i < 1000; i ++){
//     //     cuboids.push_back({rand() % 100,rand() % 100,rand() % 100});
//     // }
//     Solution solution;
//     int ret = solution.maxHeight(cuboids);
//     return 0;
// }