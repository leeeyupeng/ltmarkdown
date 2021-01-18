#include"leetcode.h"
class Solution {
private:
    int n;
    vector<int> vus;
    int parent(int index){
        if(vus[index] == index){return index;}
        vus[index] = parent(vus[index]);
        return vus[index];
    }
    void un(int _a,int _b){
        _a = parent(_a);
        _b = parent(_b);
        vus[_b] = _a;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        this->n = isConnected.size();
        vus = vector<int>(n,0);
        for(int i = 0; i < n; i ++){
            vus[i] = i;
        }
        for(int i = 0; i < n; i ++){
            for(int j = i + 1;j < n; j ++){
                if(isConnected[i][j] == 1){
                    un(i,j);
                }
            }
        }
        int ret = 0;
        for(int i = 0; i < n; i ++){
            if(vus[i] == i){
                ret ++;
            }
        }
        return ret;
    }
};