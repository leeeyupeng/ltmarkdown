#include"leetcode.h"

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int v = 0;
        for(int i = 0; i < m; i ++){
            v = matrix[0][i];
            for(int j = 1 ; j < n && i + j < m; j ++){
                if(v!=matrix[j][i+j]){return false;}
            }
        }
        for(int i = 1;i < n; i ++){
            v = matrix[i][0];
            for(int j = 1; j < m&& i+j < n; j ++){
                if(v!=matrix[i+j][j]){return false;}
            }
        }
        return true;
    }
};