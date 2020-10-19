#include"leetcode.h"

class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int ansget = 0;
        int ansrunningnums = 0;
        int n = customers.size();
        int indexcustomer = 0;
        int numscustomers=0;
        int waitcustomers = 0;
        int numsrunning=0;
        int nowget;
        while(indexcustomer<n || waitcustomers > 0){
            if(numsrunning >= indexcustomer && indexcustomer<n){
                waitcustomers+=customers[indexcustomer];
                indexcustomer++;
            }
            numsrunning ++;
            numscustomers+=min(4,waitcustomers);
            waitcustomers = max(0,waitcustomers - 4);
            nowget = numscustomers * boardingCost - runningCost * numsrunning;
            if(ansget<nowget){
                ansget = nowget;ansrunningnums = numsrunning;
            }
        }

        if(ansget == 0){return -1;}
        return ansrunningnums;
    }
};

// int main(){
//     Solution solution;
//     vector<int>customers={8,3};
//     int ans = solution.minOperationsMaxProfit(customers,5,6);
//     return ans;
// }