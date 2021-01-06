#include"leetcode.h"

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> vret(n,1);
        
        for(int i = 1; i < n; i ++){
            if(ratings[i] > ratings[i-1]){
                vret[i] = max(vret[i],vret[i-1]+1);
            }
        }
        for(int i = n-2;i >=0; i --){
            if(ratings[i] > ratings[i+1]){
                vret[i] = max(vret[i],vret[i+1]+1);
            }
        }

        int ret = 0;
        for(int i = 0; i < n; i ++){
            ret+=vret[i];
        }
        return ret;
    }
};

// int main(){
//     Solution solution;
//     vector<int> ratings={
// 1,2,2
//     };

//     int ret = solution.candy(ratings);
//     cout<<ret<<endl;
//     return 0;
// }