#include"leetcode.h"

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        pair<int,int> step[3] = {{a,1},{a-b,2},{a-b-b,3}};
        int vfn = x+a;
        vector<char> vf(vfn+1,1);
        int fn = forbidden.size();
        for(int i = 0; i < fn; i ++){
            if(forbidden[i] <= vfn){
                vf[forbidden[i]] = 0;
            }
        }

        vector<int> dp(x+1,-1);
        dp[0] = 0;
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