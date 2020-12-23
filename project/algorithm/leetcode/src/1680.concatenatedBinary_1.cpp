#include"leetcode.h"

# define MODMAX 1000000007
class Solution {
    public:
    int concatenatedBinary(int n) {
        unsigned long long ret = 0;
        int shift = 0;
        for(int i = 1; i <= n; i ++){
            if((i&(i-1))==0){
                shift++;
            }
            ret = ((ret<<shift) + i)% MODMAX;
        }
        return ret;
    }
};

// int main(){
//     Solution solution;
//     int ans = solution.concatenatedBinary(12);

//     return 0;
// }