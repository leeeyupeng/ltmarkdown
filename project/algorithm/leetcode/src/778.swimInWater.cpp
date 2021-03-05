#include"leetcode.h"

class Solution {
private:
    pair<int,int> find(vector<vector<pair<int,int>>> &us,pair<int,int> index){
        if(us[index.first][index.second] != index){
            us[index.first][index.second] = find(us,us[index.first][index.second]);
        }
        return us[index.first][index.second];
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int,int>> vgrid(n*n,{0,0});
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++){
                vgrid[grid[i][j]] = {i,j};
            }
        }
        vector<vector<pair<int,int>>> us(n,vector<pair<int,int>>(n,{0,0}));
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++){
                us[i][j] = {i,j};
            }
        }
        pair<int,int> a;
        pair<int,int> b;
        pair<int,int> s={0,0},t={n-1,n-1};
        pair<int,int> ps,pt;
        vector<pair<int,int>> offset={{-1,0},{1,0},{0,-1},{0,1}};
        for(int i = 0; i < n*n; i ++){
            a = find(us,vgrid[i]);
            for(int j = 0; j < 4; j ++){
                b = {vgrid[i].first + offset[j].first,vgrid[i].second + offset[j].second};
                if(b.first >= 0 && b.first < n && b.second >= 0 && b.second < n && grid[b.first][b.second]<=i){
                    b = find(us,b);
                    if(a!=b){
                        us[b.first][b.second] = a;
                    }

                }
            }
            ps = find(us,s);
            pt = find(us,t);
            if(ps==pt){
                return i;
            }
        }
        return -1;
    }
};