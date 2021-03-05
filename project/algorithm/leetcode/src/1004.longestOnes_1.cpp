#include"leetcode.h"

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int n = A.size();
        if(n==0){return 0;}
        int ret = 0;
        int i = 0,j=0;
        int counter = 0;
        while(j<n){
            if(A[j] == 1){j++;}
            else{
                if(counter == K){
                    if(A[i] == 0){counter--;}
                    i ++;
                }
                else{
                    counter++;
                    j++;
                }
            }
            ret = max(ret,j-i);
        }
        return ret;
    }
};

// int main(){
//     Solution solution;
//     vector<int> A={
// 0,0,0,1
//     };

//     int K = 4;
//     auto ret = solution.longestOnes(A,K);
//     return 0;
// }