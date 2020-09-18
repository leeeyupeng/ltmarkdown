#include"leetcode.h"

class Solution {
public:
    int minJump(vector<int>& jump) {
        int n = jump.size();
        int* f = new int[n];
        int* maxdis = new int[n];
        for(int i = 0; i < n; i ++){f[i]=INT_MAX;maxdis[i]=0;}
        int temp;
        f[0] = 0;
        maxdis[0] = 0;
        maxdis[1] = jump[0];
        int w=1;
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            maxdis[w]>i?:w++;
            f[i]=min(f[i],w+1);
            if(i+jump[i]>=n){ans=min(ans,f[i]+1);}
            else{
                f[i+jump[i]]=min(f[i+jump[i]],f[i]+1);
                maxdis[f[i+jump[i]]]=max(maxdis[f[i+jump[i]]],i+jump[i]);
            }         
        }

        return ans;
    }
};

// int main(){
//     vector<int> jump={
//         4,6,10,8,3,5,3,5,7,8,6,10,3,7,3,10,7,10,10,9,1,4,7,4,8,6,9,8,8,2,7,2,4,5,4,3,3,2,2,2,3,4,4,1,1,5,6,8,1,2
//     };
//     Solution solution;
//     int ans = solution.minJump(jump);
//     return 0;
// }