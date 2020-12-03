#include"leetcode.h"

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size();
        if(n==0){return 0;}
        int ans = 0;
        vector<int> ab;
        vector<int> cd;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++){
                ab.push_back(A[i] + B[j]);
                cd.push_back(C[i] + D[j]);
            }
        }
        sort(ab.begin(),ab.end());
        sort(cd.begin(),cd.end());
        int nn = ab.size();
        int value = 0;
        int j1,j2,jmid;
        int sj,ej;
        for(int i = 0; i < nn; i ++){
            value = ab[i];
            j1 = 0;
            j2 = nn;
            while(j1<j2){
                jmid = (j1+j2)>>1;
                if(value + cd[jmid]<0){
                    j1=jmid+1;
                }
                else{
                    j2 = jmid;
                }
            }
            sj = j1;
            j1 = 0;
            j2 = nn;
            while(j1<j2){
                jmid = (j1+j2)>>1;
                if(value + cd[jmid]<=0){
                    j1=jmid+1;
                }
                else{
                    j2 = jmid;
                }
            }
            ej = j1;
            if(ej-sj > 0){
                ans += ej-sj;
            }
        }

        return ans;
    }
};

// int main(){
//     Solution solution;
//     vector<int> A={0};
//     vector<int> B={0};
//     vector<int> C={0};
//     vector<int> D={0};
//     int ans = solution.fourSumCount(A,B,C,D);

//     return 0;
// }