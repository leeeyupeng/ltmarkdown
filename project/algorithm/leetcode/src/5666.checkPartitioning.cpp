#include"leetcode.h"

class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.length();
        vector<vector<char>> dp(n+1,vector<char>(3,0));
        unordered_set<int> uset;
        for(int k = 0; k < n; k ++){
            uset.insert(k*2010 + k);
            for(int step = 1;k - step >= 0 && k + step < n; step ++){
                if(s[k-step] == s[k + step]){uset.insert((k-step) * 2010 + k + step);}
                else{break;}
            }

            for(int step = 0;k - step >= 0 && k + step + 1 < n; step ++){
                if(s[k-step] == s[k + step + 1]){uset.insert((k-step) * 2010 + k + step + 1);}
                else{break;}
            }
        }
        int key=0;
        for(int i = 0; i < n; i ++){
            dp[i+1][1] = dp[i][0];
            dp[i+1][2] = dp[i][1];
            for(int j = 0; j <= i; j ++){
                key = j * 2010 + i;
                if(uset.find(key) != uset.end()){
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