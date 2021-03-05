#include"leetcode.h"

class Solution {
public:
    int countEval(string s, int result) {
        int n = s.length();
        if(n==0){return 0;}
        int on = n >> 1;
        int dn = n - on;
        vector<vector<int>> dp0(dn,vector<int>(dn,0));
        vector<vector<int>> dp1(dn,vector<int>(dn,0));
        for(int i = 0; i < dn; i ++){
            dp0[i][i] = s[(i<<1)] == '1' ? 0 : 1;
            dp1[i][i] = s[(i<<1)] == '1' ? 1 : 0;
        }
        int k,i,j;
        int op;
        for(k = 1; k < dn; k ++){
            for(i = 0; i + (k) < dn; i ++){
                j = i + (k);
                for(op = i; op <= (j) - 1; op ++){
                    if(s[(op<<1) + 1] == '&'){
                        dp0[i][j] += dp0[i][op] * dp0[op+1][j] + dp0[i][op] * dp1[op+1][j] + dp1[i][op] * dp0[op+1][j];
                        dp1[i][j] += dp1[i][op] * dp1[op+1][j];
                    }
                    else if(s[(op<<1) + 1] == '|'){
                        dp0[i][j] += dp0[i][op] * dp0[op+1][j];
                        dp1[i][j] += dp0[i][op] * dp1[op+1][j] + dp1[i][op] * dp0[op+1][j] + dp1[i][op] * dp1[op+1][j];
                    }
                    else if(s[(op<<1) + 1] == '^'){
                        dp0[i][j] += dp0[i][op] * dp0[op+1][j] + dp1[i][op] * dp1[op+1][j];
                        dp1[i][j] += dp0[i][op] * dp1[op+1][j] + dp1[i][op] * dp0[op+1][j];
                    }
                    else{
                        cout<<"error"<<endl;
                    }
                }
            }
        }

        if(result == 0){return dp0[0][dn-1];}
        else{return dp1[0][dn-1];}
    }
};

// int main(){
//     Solution solution;
//     string s = "0&0&0&1^1|0";
//     int result = 1;
//     auto ret = solution.countEval(s,result);

//     return 0;
// }