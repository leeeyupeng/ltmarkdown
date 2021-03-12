#include"leetcode.h"

class Solution {
private:
    long long _cuttingRope(int n,int m){
        long long d = n / m;
        long long mod = n % m;
        long long ret = 1;
        for(int i = 0; i < m-mod;i ++){
            ret = (ret * d) % (1000000007);
        }
        for(int i = 0; i < mod; i ++){
            ret = (ret * (d+1))% (1000000007);
        }
        return ret;
    }
public:
    int cuttingRope(int n) {
        long long ret = _cuttingRope(n,max(2,n/3 + (n%3 == 2?1:0)));
        ret = ret % (1000000007);
        return ret;
    }
};
