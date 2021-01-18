#include"leetcode.h"

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        pair<int,int> step[2] = {{a,1},{a-b,2}};
        while(step[1].first < 0){
            step[1].first += a;
            step[1].second ++;
        }
        vector<int> dp(x+1,-1);
        dp[0] = 0;

        int vfn = x+a;
        vector<char> vf(vfn+1,1);
        int fn = forbidden.size();
        for(int i = 0; i < fn; i ++){
            if(forbidden[i] <= vfn){
                vf[forbidden[i]] = 0;
            }
        }
        for(int i = 1; i <= x;i++){
            if(vf[i]==0){continue;}
            if(i-step[0].first>=0 && dp[i-step[0].first] != -1){
                if(dp[i]==-1){
                    dp[i] = dp[i-step[0].first] + step[0].second;
                }
                else{
                    dp[i] = min(dp[i],dp[i-step[0].first] + step[0].second);
                }
            }

            if(i-step[1].first>=0 && dp[i-step[1].first] != -1 && vf[i-step[1].first + a] == 1 && i-step[1].first + a - b >= 0 && vf[i-step[1].first + a - b] == 1){
                if(dp[i]==-1){
                    dp[i] = dp[i-step[1].first] + step[1].second;
                }
                else{
                    dp[i] = min(dp[i],dp[i-step[1].first] + step[1].second);
                }
            }
        }

        return dp[x];
    }
};

// int main(){
//     vector<int> forbidden={
// 14,4,18,1,15
//     };

//     Solution solution;
//     int ret = solution.minimumJumps(forbidden,3,15,9);

//     return 0;
// }