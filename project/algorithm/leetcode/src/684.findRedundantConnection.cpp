#include"leetcode.h"
class Solution {
private:
    int n;
    int* us;
    int father(int v){
        if(us[v] == v){return v;}
        us[v]=father(us[v]);
        return us[v];
    }
    bool isunion(int v1,int v2){
        return father(v1) == father(v2);
    }
    void unionset(int v1,int v2){
        us[father(v2)] = father(v1);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n = edges.size();
        us=new int[n+1];
        for(int i = 0; i <= n; i ++){
            us[i]=i;
        }
        int v1father;
        int v2father;
        for(int i = 0; i < n; i ++){
            v1father = father(edges[i][0]);
            v2father = father(edges[i][1]);
            if(v1father == v2father){
                return edges[i];
            }
            unionset(v1father,v2father);
        }
        return {0,0};
    }
};

// int main(){
//     Solution solution;
//     vector<vector<int>> edges={
//         {1,4},
//         {3,4},
//         {1,3},
//         {1,2},
//         {4,5},
//     };
//     vector<int> ans = solution.findRedundantConnection(edges);
//     return 0;
// }