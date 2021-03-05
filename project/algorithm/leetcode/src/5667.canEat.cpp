#include"leetcode.h"

class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();
        int qn = queries.size();
        vector<bool> answer(qn,false);
        vector<long long> sums(n,0);
        for(int i = 1; i < n; i ++){
            sums[i] = sums[i-1] + candiesCount[i-1]; 
        }
        long long favoriteType, favoriteDay, dailyCap;
        for(int i = 0; i < qn; i ++){
            favoriteType = queries[i][0];
            favoriteDay = queries[i][1];
            dailyCap = queries[i][2];
            if(sums[favoriteType]<= favoriteDay * dailyCap + dailyCap - 1 && sums[favoriteType] + candiesCount[favoriteType]-1>=favoriteDay){
                answer[i] = true;
            }
            else{
                answer[i] = false;
            }
        }
        return answer;
    }
};

// int main()
// {
//     vector<int> candiesCount = {
//         46,5,47,48,43,34,15,26,11,25,41,47,15,25,16,50,32,42,32,21,36,34,50,45,46,15,46,38,50,12,3,26,26,16,23,1,4,48,47,32,47,16,33,23,38,2,19,50,6,19,29,3,27,12,6,22,33,28,7,10,12,8,13,24,21,38,43,26,35,18,34,3,14,48,50,34,38,4,50,26,5,35,11,2,35,9,11,31,36,20,21,37,18,34,34,10,21,8,5
//     };

//     vector<vector<int>> queries={
//         {85,54,42}
//     };

//     Solution solution;
//     auto ret = solution.canEat(candiesCount,queries);

//     return 0;
// }