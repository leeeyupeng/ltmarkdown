#include"leetcode.h"

class Solution {
    int find(vector<int> us,int index){
        if(us[index] != index){
            us[index] = find(us,us[index]);
        }
        return us[index];
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if(m<n-1){return -1;}
        int counter = 0;
        vector<int> us(n,0);
        for(int i = 0; i < n; i ++){us[i] = i;}
        int a,b;
        for(int i = 0; i < m; i ++){
            a = find(us,connections[i][0]);
            b = find(us,connections[i][1]);
            if(a!=b){
                counter ++;
                us[b] = a;
            }
        }
        
        return n-1-counter;
    }
};