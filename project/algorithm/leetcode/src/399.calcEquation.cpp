#include"leetcode.h"

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string,int> um;
        int umcnt = 0;
        vector<vector<double>> matrix(n<<1,vector<double>(n<<1,-1.0f));
        int a,b;
        for(int i = 0; i < n; i ++){
            if(um.find(equations[i][0])== um.end()){
                um.insert({equations[i][0],umcnt++});
            }
            if(um.find(equations[i][1])== um.end()){
                um.insert({equations[i][1],umcnt++});
            }
            matrix[um[equations[i][0]]][um[equations[i][1]]] = values[i];
            matrix[um[equations[i][1]]][um[equations[i][0]]] = 1.0f/values[i];
        }

        for(int k = 0; k < umcnt; k ++){
            for(int i = 0; i < umcnt; i ++){
                for(int j = 0; j < umcnt; j ++){
                    if(matrix[i][k]!=-1.0f && matrix[k][j]!=-1.0f){
                        if(matrix[i][j] == -1.0f){
                            matrix[i][j] = matrix[i][k] * matrix[k][j];
                        }
                    }
                }
            }
        }
        int qn = queries.size();
        vector<double> ans(qn,-1.0f);
        for(int i = 0; i < qn; i ++){
            if(um.find(queries[i][0])!=um.end() && um.find(queries[i][1])!=um.end()){
                ans[i] = matrix[um[queries[i][0]]][um[queries[i][1]]];
            }
            else
            {
                ans[i] = -1.0f;
            }
        }
        return ans;
    }
};