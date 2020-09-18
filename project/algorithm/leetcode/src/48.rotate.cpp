#include"leetcode.h"

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int record = 0;
        int maxindex = n-1;
        int ii,jj;
        for(int i = 0; i < n;i++){
            for(int j = i;j<n-i-1;j++){
                record = matrix[maxindex-j][i];
                matrix[maxindex-j][i]=matrix[maxindex-i][maxindex-j];
                matrix[maxindex-i][maxindex-j] = matrix[j][maxindex-i];
                matrix[j][maxindex-i] = matrix[i][j];
                matrix[i][j] = record;
            }
        }
    }
};

// int main(){
//     vector<vector<int>> matrix={
//         {1,2,3,11},
//         {4,5,6,22},
//         {7,8,9,33},
//         {41,42,43,44}
//     };
//     Solution solution;
//     solution.rotate(matrix);
//     return 0;
// }