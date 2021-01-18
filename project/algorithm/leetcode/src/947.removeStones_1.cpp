#include"leetcode.h"

class Solution {
private:
    inline bool isconnect(vector<int>&a,vector<int>&b){
        return a[0] == b[0] || a[1] == b[1];
    }
    int find(vector<int> &us,int index){
        if(us[index] == index){return us[index];}
        us[index] = find(us,us[index]);
        return us[index];
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int ret = 0;
        vector<int> us(n,0);
        for(int i = 0; i < n; i ++){
            us[i] = i;
        }
        for(int i = 0; i < n; i ++){
            for(int j = i+1;j < n;j ++){
                if(isconnect(stones[i],stones[j])){
                    us[find(us,j)] = find(us,i);
                }                
            }
        }
        for(int i = 0; i < n; i ++){
            if(us[i] != i){ret++;}
        }
        return ret;
    }
};