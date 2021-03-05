#include"leetcode.h"

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int mn = m + n;
        int aindex = m - 1;
        int bindex = n -1;
        for(int i = mn - 1; i >= 0; i --){
            if(aindex < 0){
                A[i] = B[bindex];
                bindex--;
            }
            else if(bindex < 0){
                A[i] = A[aindex];
                aindex--;
            }
            else if(A[aindex] >= B[bindex]){
                A[i] = A[aindex];
                aindex--;
            }
            else{
                A[i] = B[bindex];
                bindex--;
            }
        }
    }
};