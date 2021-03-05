#include"leetcode.h"

class Solution {
public:
    int getKthMagicNumber(int k) {
        vector<int> v(k,0);
        v[0] = 1;
        int n = 1;
        int nextmin;
        for(int i = 1;i < k; i ++){
            nextmin = v[i-1] * 3;
            for(int j = 0; j < i;j ++){
                if(v[j] * 3 > v[i-1]){
                    nextmin = min(nextmin,v[j] * 3);
                }
                else if(v[j] * 5 > v[i-1]){
                    nextmin = min(nextmin,v[j] * 5);
                }
                else if(v[j] * 7 > v[i-1]){
                    nextmin = min(nextmin,v[j] * 7);
                }
            }
            v[i] = nextmin;
        }
        return v[k-1];
    }
};