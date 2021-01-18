#include"leetcode.h"

class Solution {
private:
    int find(vector<int>& us,int index){
        if(us[index] == index){
            return us[index];
        }
        us[index] = find(us,us[index]);
        return us[index];
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> us(n+1,0);
        for(int i = 0; i <= n; i ++){
            us[i] = i;
        }
        int a,b;
        for(int i = 0; i < n; i ++){
            a = find(us,edges[i][0]);
            b = find(us,edges[i][1]);
            if(a==b){
                return edges[i];
            }else{
                us[b] = a;
            }
        }
        return {};
    }
};