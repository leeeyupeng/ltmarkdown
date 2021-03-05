#include"leetcode.h"

class Solution {
public:
    int numberOf2sInRange(int n) {
        long long bit = 1;
        long long bitnums = 0;
        long long bitmodnums = 0;
        int value = n;
        while(value>0){
            bitmodnums = bitnums * (value%10) + bitmodnums;
            if(value%10 == 2){
                bitmodnums += n % bit  + 1;
            }
            else if(value % 10 > 2){
                bitmodnums += bit;
            }
            bitnums = bitnums * 10 + bit;
            value /= 10;
            bit=bit*10;
        }
        return bitmodnums;
    }
};

// int main(){
//     Solution solution;
//     auto ret = solution.numberOf2sInRange(218);

//     return 0;
// }
