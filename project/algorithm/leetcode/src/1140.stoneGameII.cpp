#include"leetcode.h"

class Solution {
private:
    int n;
    int _max(vector<int>& piles,int index,int m)
    {
        int value=0;
        int temp=0;
        int sum=0;
        for(int x = 0;x < (m<<1) && index+x < n; x ++){
            sum+= piles[index+x];
            temp = sum + _min(piles,index+x+1,max(m,x+1));
            value = max(value,temp);
        }
        return value;
    }
    int _min(vector<int>& piles,int index,int m){
        int value=0;
        int temp=0;
        for(int x = 0;x < (m<<1) && index+x < n; x ++){
            temp = _max(piles,index+x+1,max(m,x+1));
            if(value == 0){
                value = temp;
            }
            else{
                value = min(value,temp);
            }
        }
        return value;
    }
public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        int ans = _max(piles,0,1);
        return ans;
    }
};

// int main(){
//     Solution solution;
//     vector<int> piles={
//         2,7,9,4,4
//     };

//     int ans = solution.stoneGameII(piles);

//     return 0;
// }