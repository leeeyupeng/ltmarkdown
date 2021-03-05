#include"leetcode.h"

class Solution {
private:
    int getbitnums(int num){
        int ret = 0;
        while(num!=0){
            ret += num&0x1;
            num=num>>1;
        }
        return ret;
    }
public:
    vector<int> countBits(int num) {
        vector<int>  ret(num+1,0);
        ret[0] = 0;
        if(num==0){return ret;}
        ret[1] = 1;
        if(num==1){return ret;}
        ret[2] = 1;
        if(num==2){return ret;}
        int bitnum = 2;
        for(int i = 3;i <= num; i ++){
            if(i == (bitnum << 1)){
                bitnum = i;
                ret[i] = 1;
            }
            else{
                ret[i] = ret[i-bitnum] + ret[bitnum];
            }
        }
        return ret;
    }
};