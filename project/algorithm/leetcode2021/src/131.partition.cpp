#include"leetcode.h"

class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<char>> ispalindrome(n,vector<char>(n,0));
        for(int i = 0; i < n; i ++){
            for(int step = 0;i - step >= 0 && i + step < n;step ++){
                if(s[i-step] != s[i+step]){
                    break;
                }
                ispalindrome[i-step][i+step] = 1;
            }

            for(int step = 0;i - step >= 0 && i + step + 1 < n;step ++){
                if(s[i-step] != s[i+step + 1]){
                    break;
                }
                ispalindrome[i-step][i+step + 1] = 1;
            }
        }
        vector<vector<vector<string>>> dp(n);
        dp[0].push_back({{s[0]}});
        for(int i = 1;i < n; i ++){   
            for(int j = 0;j <= i ;j ++){
                if(ispalindrome[j][i] == 1){
                    if(j == 0){
                        dp[i].push_back({s.substr(j,i+1)});
                    }
                    else{
                        for(int k = 0; k < dp[j-1].size();k ++){
                            dp[i].push_back(dp[j-1][k]);
                            dp[i].back().push_back(s.substr(j,i+1-j));
                        }
                    }
                }
            }         
        }

        return dp[n-1];
    }
};

// int main(){
//     Solution solution;
//     string s = "aab";
//     auto ret = solution.partition(s);
//     return 0;
// }