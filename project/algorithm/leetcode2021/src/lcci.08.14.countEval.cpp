#include"leetcode.h"

class Solution {
public:
    int countEval(string s, int result) {
        int n = s.length();
        if(n==0){return 0;}
        int on = n >> 1;
        int dn = n - on;
        vector<int> dp0(dn,0);
        vector<int> dp1(dn,0);
        dp0[0] = s[0] == '1'?0:1;
        dp1[0] = s[0] == '1'?1:0;
        if(n == 1){
            if(result == 0){return dp0[0];}
            else{return dp1[0];}
        }
        if(s[1] == '&'){
            dp1[1] = s[2] == '1' ? dp1[0] : 0;
            dp0[1] = dp1[1] == 0?1:0;
        }
        else if(s[1] == '|'){
            dp1[1] = s[2] == '1' ? 1 : dp1[0];
            dp0[1] = dp1[1] == 0?1:0;
        }
        else{
            dp1[1] = s[2] == '1' ? dp0[0] : dp1[0];
            dp0[1] = dp1[1] == 0?1:0;
        }
        if(n == 3){
            if(result == 0){return dp0[1];}
            else{return dp1[1];}
        }
        int ipos;
        char value;
        for(int i = 2; i < dn; i ++){
            ipos = i << 1;
            if(s[ipos-1] == '&'){
                dp1[i] += s[ipos] == '1' ? dp1[i-1] : 0;
                dp0[i] += s[ipos] == '1' ? dp0[i-1] : (dp0[i-1] + dp1[i-1]);
                value = s[ipos] == '1' && s[ipos-2] == '1' ? 1 : 0;
            }
            else if(s[ipos-1] == '|'){
                dp1[i] += s[ipos] == '1' ? (dp0[i-1] + dp1[i - 1]) : dp1[i-1];
                dp0[i] += s[ipos] == '1' ? 0 : dp0[i-1];
                value = s[ipos] == '1' || s[ipos-2] == '1' ? 1 : 0;
            }
            else{
                dp1[i] += s[ipos] == '1' ? dp0[i-1] : dp1[i-1];
                dp0[i] += s[ipos] == '1' ? dp1[i-1] : dp0[i-1];
                value = (s[ipos] == '1'?1:0)^(s[ipos-2] == '1' ? 1 : 0);
            }

            if(s[ipos - 3] == '&'){
                dp1[i] += value == 1 ? dp1[i-2] : 0;
                dp0[i] += value == 1 ? dp0[i-2] : (dp0[i-2] + dp1[i-2]);
            }
            else if(s[ipos-3] == '|'){
                dp1[i] += value == 1 ? (dp0[i-2] + dp1[i-2]) : dp1[i-2];
                dp0[i] += value == 1 ? 0 : dp0[i-2];
            }
            else{
                dp1[i] += value == 1 ? dp0[i-2] : dp1[i-2];
                dp0[i] += value == 1 ? dp1[i-2] : dp0[i-2];
            }
        }

        if(result == 0){return dp0[dn-1];}
        else{return dp1[dn-1];}
    }
};

// int main(){
//     Solution solution;
//     string s = "1^0|0|1";
//     int result = 0;
//     auto ret = solution.countEval(s,result);

//     return 0;
// }