#include"leetcode.h"

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();

        vector<vector<int>> counter(200+1);
        for(int i = 0; i < n; i ++){
            counter[aliceValues[i] + bobValues[i]].push_back(i);
        }

        int alicevalue = 0;
        int bobvalue = 0;
        int count = 0;

        for(int i = 200; i > 0;i --)
        {
            for(int j = counter[i].size()-1; j >= 0; j --){
                if((count&0x1) == 0x0){
                    alicevalue+=aliceValues[counter[i][j]];
                }
                else{
                    bobvalue+=bobValues[counter[i][j]];
                }
                count ++;
            }
        }
        if(alicevalue > bobvalue){
            return 1;
        }
        else if(alicevalue==bobvalue){
            return 0;
        }
        else{
            return -1;
        }
        return 0;
    }
};

// int main()
// {
//     Solution solution;
//     vector<int> aliceValues={
// 9,8,3,8
//     };
//     vector<int> bobValues={
// 10,6,9,5
//     };
//     int ans = solution.stoneGameVI(aliceValues,bobValues);

//     return 0;
// }