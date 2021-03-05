#include"leetcode.h"

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int n = A.size();
        if(n==0){return 0;}
        int ret = 0;
        vector<int> counter(n,0);
        counter[0] = A[0]==1?0:1;
        for(int i = 1; i < n; i ++){
            counter[i] = counter[i-1] + (A[i]==1?0:1);
        }
        int i,j;
        int c;
        int l,r;
        int mid;
        for(i = 0; i < n; i ++){
            if(i == 0){
                c = K;
            }
            else{
                c = K + counter[i-1];
            }
            l = i,r = n;
            while(l<r){
                mid = (l+r)>>1;
                if(counter[mid] > c){
                    r = mid;
                }
                else{
                    l = mid+1;
                }
            }

            ret = max(ret,r-i);
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