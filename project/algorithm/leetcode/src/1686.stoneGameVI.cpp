#include"leetcode.h"

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<int> index(n);
        for(int i = 0; i < n; i ++){
            index[i] = i;
        }

        sort(index.begin(),index.end(),[&aliceValues,&bobValues](int a,int b){
            if((aliceValues[a] - bobValues[b]) == (aliceValues[b] - bobValues[a])){
                return aliceValues[a] < aliceValues[b];
            }
            return (aliceValues[a] - bobValues[b]) < (aliceValues[b] - bobValues[a]);
        });

        int alicevalue = 0;
        int bobvalue = 0;
        int first = (n-1) & 0x1;
        for(int i = n-1;i >= 0;i --){
            if((i&0x1)==first){
                alicevalue += aliceValues[index[i]];
            }
            else{
                bobvalue += bobValues[index[i]];
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