#include"leetcode.h"

class Solution {
    unordered_set<int> set;
    unordered_map<int,int> map;
    int dfs(int value){
        if(map.find(value)!=map.end()){return map[value];}
        if(set.find(value)!=set.end()){return INT_MAX;}
        int steps = INT_MAX;
        int i = 0;
        while((value & (1<<i)) == 0x0){i++;}
        i++;
        if(i<32){
            steps = min(steps,dfs((value&(~(1<<i))) + ((value&(1<<i))^(1<<i))) + 1);
        }
        steps = min(steps,dfs((value&(~0x1)) + ((value&0x1)^0x1)) + 1);
        map[value] = steps;
    }
public:
    int minimumOneBitOperations(int n) {
        if(n == 0){return 0;}
        int value = n;
        map[0] = 0;
        int ans = dfs(value);
        return ans;
    }
};

// int main(){
//     Solution solution;
//     int ans = solution.minimumOneBitOperations(10);
//     return 0;
// }