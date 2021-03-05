#include"leetcode.h"

#define INFINITY -100010
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int m = adjacentPairs.size();
        int n = m +1;
        unordered_map<int,pair<int,int>> umap;
        for(int i = 0; i < m; i ++){
            if(umap.find(adjacentPairs[i][0]) == umap.end()){
                umap.insert({adjacentPairs[i][0],{adjacentPairs[i][1],INFINITY}});
            }
            else{
                umap[adjacentPairs[i][0]].second = adjacentPairs[i][1];
            }
            if(umap.find(adjacentPairs[i][1]) == umap.end()){
                umap.insert({adjacentPairs[i][1],{adjacentPairs[i][0],INFINITY}});
            }
            else{
                umap[adjacentPairs[i][1]].second = adjacentPairs[i][0];
            }
        }
        int start=-1;
        for(unordered_map<int,pair<int,int>>::iterator ite = umap.begin();ite!=umap.end(); ite++){
            if((*ite).second.second == INFINITY){
                start = (*ite).first;
                break;
            }
        }  
        vector<int> ret(n,0);
        int index = start;
        int counter = 0;
        int next;
        while(counter < n&&index!=INFINITY){
            ret[counter++] = index;
            if(umap[index].first!=INFINITY){
                next = umap[index].first;
                umap[index].first = INFINITY;
            }
            else{
                next = umap[index].second;
                umap[index].second = INFINITY;
            }

            if(umap[next].first == index){
                umap[next].first = INFINITY;
            }
            else{
                umap[next].second = INFINITY;
            }
            index = next;      
        }   
        return ret; 
    }
};

// int main(){
//     vector<vector<int>> adjacentPairs={
//         {2,1},{3,4},{3,2}
//     };

//     Solution solution;
//     auto ret = solution.restoreArray(adjacentPairs);
//     return 0;
// }