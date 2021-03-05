#include"leetcode.h"

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> matrix2(n,vector<int>(m,0));
        for(int j = 0; j < m; j ++){            
            for(int i = 0; i < n; i ++){
                if(i>0){
                    matrix2[i][j] ^= matrix2[i-1][j];
                }
                matrix2[i][j] ^= matrix[i][j];
            }
        }
        vector<vector<int>> matrix3(n,vector<int>(m,0));
        for(int i = 0; i < n; i ++){            
            for(int j = 0; j < m; j ++){    
                if(j>0){       
                    matrix3[i][j] ^= matrix3[i][j-1];
                }
                matrix3[i][j] ^= matrix2[i][j];
                if(pq.size() < k)
                {
                    pq.push(matrix3[i][j]);
                }
                else if(pq.top() < matrix3[i][j]){
                    pq.pop();
                    pq.push(matrix3[i][j]);
                }
            }
        }
        return pq.top();
    }
};

// int main(){
//     vector<vector<int>> matrix={
//         {5,2},
//         {1,6}
//     };

//     Solution solution;
//     int ret = solution.kthLargestValue(matrix,2);
//     return 0;
// }