#include"leetcode.h"

class Solution {
private:
    int gcd(int a,int b){
        if(b == 0){
            return a;
        }
        return gcd(b,a%b);
    }
public:
    bool canMeasureWater(int x, int y, int z) {
        int a = x,b = y,c = z;
        if(a==0&&b==0){return c == 0;}
        if(b == 0){return c % a == 0;}
        if(a == 0){return c % b == 0;}
        int g = gcd(a,b);
        return a+b>=c&&c%g == 0; 
    }
};