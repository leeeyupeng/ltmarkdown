#include"leetcode.h"

class Solution {
    unordered_set<int> set;
public:
    int minimumOneBitOperations(int n) {
        if(n == 0){return 0;}
        int value = n;
        int steps = 0;
        int value1;
        int value2;
        queue<pair<int,int>> q;
        pair<int,int> item;
        q.push({n,0});
        set.insert(value);
        int i;
        int lowbit;
        int stepsnums;
        while(!q.empty()){            
            stepsnums = q.size();
            while(stepsnums>0){
                stepsnums--;
                item = q.front();
                value = item.first;
                q.pop();
                if(value == 0){return steps;}
                if(item.second!=2){            
                    lowbit=value&(-value);
                    lowbit<<=1;
                    value2 = (value&(~lowbit)) + ((value&lowbit)^lowbit); 
                    if(set.find(value2)==set.end()){q.push({value2,2});set.insert(value2);}
                }
                if(item.second!=1){
                    value1 = (value&(~0x1)) + ((value&0x1)^0x1);
                    if(set.find(value1)==set.end()){q.push({value1,1});set.insert(value1);}
                }
            }
            steps++;
        }
        return steps;
    }
};

// int main(){
//     Solution solution;
//     int ans = solution.minimumOneBitOperations(100000000);
//     return 0;
// }