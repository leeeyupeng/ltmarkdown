#include"leetcode.h"

# define MODMAX 1000000007
class Solution {
    public:
    int concatenatedBinary(int n) {
        unsigned long long ret = 0;
        stack<char> ss;
        int temp;
        vector<char> s(32,0);
        int top = -1;
        for(int i = n; i >= 1; i --){
            temp = i;
            while(temp!=0){
                ss.push(temp&0x1);
                temp=temp>>1; 
                
            }
        }

        while(!ss.empty()){
            ret<<=1;
            ret+=ss.top();
            ss.pop();
            while(ret>=MODMAX){ret-=MODMAX;}
        }
        return ret;
    }
};

// int main(){
//     Solution solution;
//     int ans = solution.concatenatedBinary(12);

//     return 0;
// }