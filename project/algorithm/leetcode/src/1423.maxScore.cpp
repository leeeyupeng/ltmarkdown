#include"leetcode.h"

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int kk = n -k;
        int ret = INT_MAX;
        int sums = 0;
        for(int i = 0; i < kk; i ++){
            sums+=cardPoints[i];
        }
        
        ret = min(ret,sums);
        for(int i = kk; i < n; i ++){
            sums += cardPoints[i];
            sums -= cardPoints[i-kk];
            ret = min(ret,sums);
        }
        sums = 0;
        for(int i = 0; i < n; i ++){
            sums+=cardPoints[i];
        }
        return sums - ret;
    }
};