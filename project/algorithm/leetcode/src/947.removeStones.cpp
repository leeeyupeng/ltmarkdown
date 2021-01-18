#include"leetcode.h"

#define MAX 10001
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> vc(MAX,0);
        vector<int> vr(MAX,0);
        for(int i = 0; i < n; i ++){
            vc[stones[i][0]] ++;
            vr[stones[i][1]] ++;
        }
        sort(stones.begin(),stones.end(),[&vc,&vr](vector<int>& a,vector<int> &b){
            if(vc[a[0]]*vr[a[1]] == vc[b[0]] * vr[b[1]]){
                return vc[a[0]]<vc[b[0]];
            }
            return vc[a[0]]*vr[a[1]] < vc[b[0]] * vr[b[1]];
        });
        int ret = 0;
        for(int i = 0; i< n; i ++){
            if(vc[stones[i][0]] > 1 || vr[stones[i][1]] > 1){
                ret ++;
                vc[stones[i][0]] --;
                vr[stones[i][1]] --;
            }
        }
        return ret;
    }
};