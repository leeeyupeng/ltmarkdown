#include"leetcode.h"

class Solution {
private:
    unordered_map<int,int> map;
    int f(int value){
        if(value == 0){return 0;}
        if(value == 1){return 1;}
        if(map.find(value)!=map.end()){return map[value];}
        int bit = -1;
        int v = value;
        while(v>0){bit++;v>>=1;}
        int ans = g(value^(1<<bit),bit-1) + 1 + (1<<(bit)) - 1;
        map[value] = ans;
        return ans;
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
            return g(value,bit-1) + 1 + (1<<(bit)) - 1;
        }
    }
public:
    int minimumOneBitOperations(int n) {
        int ans = f(n);
        return ans;
    }
};

// int main(){
//     Solution solution;
//     int n = 189342525;
//     int ans = solution.minimumOneBitOperations(n);
//     return 0;
// }