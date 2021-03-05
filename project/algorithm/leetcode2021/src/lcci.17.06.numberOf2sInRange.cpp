#include"leetcode.h"

class Solution {
private:
    int getnumberOf2_next(int k,int nums){
        int bit = k % 10;
        if(bit == 1){return nums + 1;}
        else if(bit == 2){return nums - 1;}
        else if(bit == 9){
            return getnumberOf2_next(k/10,nums);
        }
        else{
            return nums;
        }
    }
public:
    int numberOf2sInRange(int n) {
        int ret = 0;
        int nums = 0;
        for(int i = 0; i < n; i ++){
            nums = getnumberOf2_next(i,nums);
            ret += nums;
        }
        return ret;
    }
};