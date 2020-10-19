#include"leetcode.h"

class Solution {
private:
    int f(int value){
        if(value == 0){return 0;}
        if(value == 1){return 1;}
        
        int bit = -1;
        int v = value;
        while(v>0){bit++;v>>=1;}
        int ans = g(value^(1<<bit),bit-1) + 1 + f2((bit-1));
        return ans;
    }
    int bits[32];
    int f2(int bit){
        if(bits[bit]!=0){return bits[bit];}
        bits[bit] =  1+f2(bit-1)*2;
        return bits[bit];
    }

    int g(int value,int bit){
        if(bit == 0){
            if(value == 0x0){return 1;}
            else{return 0;}
        }
        if((value&(1<<bit)) == (1<<bit)){
            return f(value^(1<<bit));
        }
        else{
            return g(value,bit-1) + 1 + f2((bit-1));
        }
    }
public:
    int minimumOneBitOperations(int n) {
        for(int i = 0; i < 32; i ++){
            bits[i] = 0;
        }
        bits[0] = 1;
        int ans = f(n);
        return ans;
    }
};

// int main(){
//     Solution solution;
//     int n = 333;
//     int ans = solution.minimumOneBitOperations(n);
//     return 0;
// }