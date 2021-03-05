#include"leetcode.h"

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size();
        int ret = 0;
        for(int i = 0; i <= n-K;i++){
            if(A[i] == 0){
                for(int j = 0;j < K; j ++){
                    A[i+j]=A[i+j]==0?1:0;
                }
                ret++;
            }
            else{

            }
        }
        for(int i = n-K;i<n;i++){
            if(A[i]==0){return -1;}
        }
        return ret;
    }
};