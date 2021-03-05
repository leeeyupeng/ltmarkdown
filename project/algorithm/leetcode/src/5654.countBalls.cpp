#include"leetcode.h"

class Solution {
private:
    inline int getnumber(int index){
        int ret = 0;
        while(index!=0){
            ret += index%10;
            index /= 10;
        }
        return ret;
    }
public:
    int countBalls(int lowLimit, int highLimit) {
        vector<int> vnums(100,0);
        for(int i = lowLimit; i <= highLimit;  i++){
            vnums[getnumber(i)]++;
        }
        int ret = 0;
        for(int i = 0; i < 100; i ++){
            ret = max(ret,vnums[i]);
        }
        return ret;
    }
};