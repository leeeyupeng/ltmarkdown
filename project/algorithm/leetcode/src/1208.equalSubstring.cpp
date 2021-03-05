#include"leetcode.h"

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> vcost(n,0);
        for(int i = 0; i < n; i ++){
            vcost[i] = abs(s[i]-t[i]);
        }
        //sort(counter.begin(),counter.end());
        int ret = 0;
        int cost = 0;
        int i=0;
        int j=0;
        cost = vcost[0];
        int counter=1;
        while(j<n-1){
            if(cost <= maxCost){
                cost+=vcost[++j];
                counter++;
            }
            else{
                cost-=vcost[i++];
                counter--;
            }
            if(cost<=maxCost){
                ret = max(ret,counter);
            }
        }
        return ret;
    }
};