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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        n = edges.size();
        us=new int[n+1];
        for(int i = 0; i <= n; i ++){
            us[i]=i;
        }
        vector<int> vParent(n + 1, -1);
        for (int i = 0; i < n; i++) {
            if (vParent[edges[i][1]] == -1) {
                vParent[edges[i][1]] = i;
            }
            else
            {
                int j = vParent[edges[i][1]];
                vector<int> temp;
                temp = edges[n - 1];
                edges[n - 1] = edges[i];
                edges[i] = temp;

                temp = edges[n - 2];
                edges[n - 2] = edges[j];
                edges[j] = temp;
                break;
            }
        }

        int v1father;
        int v2father;
        for(int i = 0; i < n-1; i ++){
            v2father = father(edges[i][1]);
            v1father = father(edges[i][0]);
            if(v1father == v2father){
                return edges[i];
            }
            unionset(edges[i][0],edges[i][1]);
        }
        return edges[n-1];
    }
};

// int main(){
//     Solution solution;
//     vector<vector<int>> edges={
// {4,2},{1,5},{5,2},{5,3},{2,4}
//     };
//     vector<int> ans = solution.findRedundantDirectedConnection(edges);
//     return 0;
// }