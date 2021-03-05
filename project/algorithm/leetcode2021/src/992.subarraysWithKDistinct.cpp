#include"leetcode.h"

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int n = A.size();  
        if(n==0){return 0;}
             
        vector<int> counter(n+1,0);
        int i = 0,j = 0;
        int jj=0;
        int ret = 0;
        int nums = 0;
        int lastjnums = 0;
        counter[A[i]] ++;
        nums++;
        while(j<n-1){
            if(nums == K){
                while(jj<n && counter[A[jj]] != 0){jj++;}
                ret += jj -j;
                while(counter[A[i]] != 1){
                    counter[A[i]] --;
                    ret += jj -j;
                    i++;
                }
                counter[A[i]] --;
                if(counter[A[i]] == 0){nums --;}
                i++;
            }
            else{
                j ++;
                if(counter[A[j]] == 0){
                    nums ++;                    
                }
                counter[A[j]] ++;
            }
        }
        if(nums == K){
            ret++;
            while(counter[A[i]]!=1){
                i ++;
                ret ++;                
            }
        }
        return ret;
    }
};

// int main(){
//     vector<int> A={
// 1,2,1,3,4
//     }; 
//     int K=3;
//     Solution solution;
//     auto ret = solution.subarraysWithKDistinct(A,K);
//     return 0;
// }