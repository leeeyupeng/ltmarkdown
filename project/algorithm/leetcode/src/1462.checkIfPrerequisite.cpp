#include"leetcode.h"

class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> matrix(n,vector<int>(n,-1));
        int pn = prerequisites.size();
        for(int i = 0; i < pn; i ++){
            matrix[prerequisites[i][0]][prerequisites[i][1]] = 0;
        }
        for(int k = 0; k < n; k ++){
            for(int i = 0; i < n; i ++){
                for(int j = 0; j < n; j ++){
                    if(matrix[i][j]==-1 && matrix[i][k]!=-1 && matrix[k][j]!=-1){
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        int nq = queries.size();
        vector<bool> ans(nq,false);
        for(int i = 0; i < nq; i ++){
            ans[i] = matrix[queries[i][0]][queries[i][1]] == 0;
        }
        return ans;
    }
};