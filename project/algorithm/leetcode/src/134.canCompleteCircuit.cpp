#include"leetcode.h"

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        if(n==1){
            if(gas[0]-cost[0]>=0){return 0;}
            else{return -1;}
        }
        int startindex=0;
        int index =1;
        int gc = gas[0]-cost[0];
        while(index!=startindex){
            if(gc>=0){                
                gc+=gas[index]-cost[index];
                index++;
                if(index>=n){index-=n;}
            }
            else if(startindex < index){
                gc = gas[index]-cost[index];
                startindex = index;
                index++;
                if(index>=n){index-=n;}
            }
            else {
                startindex = -1;
                break;
            }
        }
        if(gc<0){startindex = -1;}
        return startindex;
    }
};