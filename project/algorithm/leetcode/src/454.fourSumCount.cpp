#include"leetcode.h"

class Solution {
private:
    int n;
    int first;
    int last;
    int ans;
    void dfs(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D,int index,int value){
        if(index == 4){
            if(value == 0){
                ans ++;
            }
            return;
        }
        int min,max;
        vector<int>* vnow;
        if(index==0){
            min = (B[last] + C[last] + D[last]);
            max = (B[first] + C[first] + D[first]);
            vnow = &A;
        }else if(index == 1){
            min = (C[last] + D[last]);
            max = (C[first] + D[first]);
            vnow = &B;
        }else if(index == 2){
            min = (D[last]);
            max = ( D[first]);
            vnow = &C;
        }
        else{
            min = 0;
            max = 0;
            vnow = &D;
        }
        min = 0-value-min;
        max = 0-value-max;

        int i=first,j=last,mid;
        while(i<j){
            mid = (i+j)>>1;
            if((*vnow)[mid]<min){i=mid+1;}
            else{j=mid;}
        }
        for(int k = i;k<n && (*vnow)[k]<=max;k++){
            dfs(A,B,C,D,index+1,value+(*vnow)[k]);
        }
    }
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        n = A.size();
        if(n==0){return 0;}
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        sort(C.begin(),C.end());
        sort(D.begin(),D.end());
        first=0;
        last=n-1;
        ans = 0;
        dfs(A,B,C,D,0,0);
        return ans;
    }
};

// int main(){
//     Solution solution;
//     vector<int> A={1,2};
//     vector<int> B={-2,-1};
//     vector<int> C={-1,2};
//     vector<int> D={0,2};
//     int ans = solution.fourSumCount(A,B,C,D);

//     return 0;
// }