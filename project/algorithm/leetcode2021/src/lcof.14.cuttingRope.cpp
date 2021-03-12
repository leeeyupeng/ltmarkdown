#include"leetcode.h"

class Solution {
private:
    int _cuttingRope(int n,int m){
        int d = n / m;
        int mod = n % m;
        int ret = 1;
        for(int i = 0; i < m-mod;i ++){
            ret *= d;
        }
        for(int i = 0; i < mod; i ++){
            ret*=d+1;
        }
        return ret;
    }
public:
    int cuttingRope(int n) {
        int ret = 0;
        int r;
        for(int i = 2; i <= n; i ++){
            r = _cuttingRope(n,i);
            ret = max(ret,r);
        }
        return ret;
    }
};
