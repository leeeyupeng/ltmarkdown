#include"leetcode.h"

class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n == 0){return 0;}
        int value = n;
        int steps = 0;
        int value1=value;
        int value2=value;
        int lowbit;
        int stepsnums;
        int maxvalue = n << 1;
        int swapvalue;
        while(true){            
            {
                value = value1;
                if(value == 0){return steps;}
                //if(value <= maxvalue)
                {   
                    lowbit=value&(-value);
                    lowbit<<=1;
                    value1 = value^lowbit;
                }
                value = value2;
                if(value == 0){return steps;}
                //if(value <= maxvalue)
                {
                    lowbit=0x1;
                    value2 = value^lowbit;
                }
                value1= value1^value2;
                value2 = value1^value2;
                value1 = value1^value2;
            }
            steps++;
        }
        return steps;
    }
};

// int main(){
//     Solution solution;
//     int n = 155154368;
//     int ans = solution.minimumOneBitOperations(n);
//     return 0;
// }