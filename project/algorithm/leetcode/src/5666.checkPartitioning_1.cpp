#include"leetcode.h"

class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.length();
        vector<vector<char>> dp(n+1,vector<char>(3,0));
        vector<vector<char>> vvmap(n,vector<char>(n,0));
        for(int k = 0; k < n; k ++){
            vvmap[k][k] = 1;
            for(int step = 1;k - step >= 0 && k + step < n; step ++){
                if(s[k-step] == s[k + step]){vvmap[(k-step)][k + step]=1;}
                else{break;}
            }

            for(int step = 0;k - step >= 0 && k + step + 1 < n; step ++){
                if(s[k-step] == s[k + step + 1]){vvmap[(k-step)][k + step + 1]=1;}
                else{break;}
            }
        }
        for(int i = 0; i < n; i ++){
            dp[i+1][1] = dp[i][0];
            dp[i+1][2] = dp[i][1];
            for(int j = 0; j <= i; j ++){
                if(vvmap[j][i] == 1){
                    if(j == 0){dp[i+1][0] = 1;}
                    dp[i+1][1] = dp[i+1][1] | dp[j][0];
                    dp[i+1][2] = dp[i+1][2] | dp[j][1];
                }
            }
        }

        return dp[n][2] == 1;
    }
};

// int main(){
//     string s="abcbdd";
//     Solution solution;
//     auto ret = solution.checkPartitioning(s);

//     return 0;
// }