#include"leetcode.h"

class Solution {
private:
    int n;
    bool check(vector<vector<char>>& matrix,int x,int y,int k){
        for(int i = 0; i < k; i ++){
            for(int j = 0; j < k; j ++){
                if(matrix[i+k][j+k] == '0'){return false;}
            }
        }
        return true;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        n = matrix.size();
        int ans = 0;

        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++){
                for(int k = max(ans,1); k <= n-i && k <= n-j; k ++){
                    if(check(matrix,i,j,k)){ans = max(ans,k);}
                    else{break;}
                }
            }
        }

        return ans;
    }
};