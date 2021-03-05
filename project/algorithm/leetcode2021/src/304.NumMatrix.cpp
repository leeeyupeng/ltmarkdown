#include"leetcode.h"

class NumMatrix {
private:
    vector<vector<int>>& matrixsums;
public:
    NumMatrix(vector<vector<int>>& matrix):matrixsums(matrix) {
        int n = matrix.size();
        if(n==0){return;}
        int m = matrix[0].size();
        for(int i = 1; i < n ; i++){
            matrixsums[i][0] += matrixsums[i-1][0];
        }
        for(int j = 1; j < m; j ++){
            matrixsums[0][j] += matrixsums[0][j-1];
        }
        for(int i = 1; i < n; i ++){
            for(int j = 1;j < m; j ++){
                matrixsums[i][j] += matrixsums[i-1][j] + matrixsums[i][j-1] - matrixsums[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1--;
        col1--;
        if(row1<0 && col1<0){
           return matrixsums[row2][col2]; 
        }
        else if(row1 < 0){
            return matrixsums[row2][col2] - matrixsums[row2][col1];
        }
        else if(col1 <0 ){
            return matrixsums[row2][col2] - matrixsums[row1][col2];
        }
        return matrixsums[row2][col2] + matrixsums[row1][col1] - matrixsums[row1][col2] - matrixsums[row2][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */