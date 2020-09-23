#include"leetcode.h"

class Solution {
private:
    int n;
    pair<int,int> *record;
    pair<int,int> minmax(vector<int>& piles,int i,int j){
        if(record[i*n+j].first!=0|| record[i*n+j].second!=0){return record[i*n+j];}
        if(i==j){return {piles[i],0};}
        pair<int,int> scorei = minmax(piles,i+1,j);
        swap(scorei.first,scorei.second);
        scorei.first+=piles[i];
        pair<int,int> scorej = minmax(piles,i,j-1);
        swap(scorej.first,scorej.second);
        scorej.first+=piles[j];
        record[i*n+j] = scorei.first>=scorej.first?scorei:scorej;
        return record[i*n+j];
    }
public:
    bool stoneGame(vector<int>& piles) {
        n = piles.size();
        record = new pair<int,int>[n*n];
        for(int i = 0; i < n*n; i ++){record[i]={0,0};}
        pair<int,int> score = minmax(piles,0,n-1);
        return score.first>score.second;
    }
};

// int main(){
//     Solution solution;
//     vector<int> piles={
//         5,3,4,5
//     };
//     bool ans = solution.stoneGame(piles);
//     return 0;
// }