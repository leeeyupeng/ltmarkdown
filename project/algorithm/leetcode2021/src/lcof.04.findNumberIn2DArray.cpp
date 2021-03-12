#include"leetcode.h"

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n==0){return false;}
        int m = matrix[0].size();
        int l = 0,r = m,mid;
        if(m>=n){
            r = m;
            for(int i = 0; i < n; i ++){
                l = 0;
                while(l<r){
                    mid = (l+r)>>1;
                    if(matrix[i][mid] < target){l = mid+1;}
                    else if(matrix[i][mid] == target){return true;}
                    else{
                        r = mid;
                    }
                }
            }
        }
        else{
            r = n;
            for(int i = 0; i < m; i ++){
                l = 0;
                while(l<r){
                    mid = (l+r)>>1;
                    if(matrix[mid][i] < target){l = mid+1;}
                    else if(matrix[mid][i] == target){return true;}
                    else{
                        r = mid;
                    }
                }
            }
        }
        return false;
    }
};