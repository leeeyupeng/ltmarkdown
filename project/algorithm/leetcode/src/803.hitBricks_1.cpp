#include"leetcode.h"

class Solution {
private:
    int sums = 0;
    pair<int,int> find(vector<vector<pair<pair<int,int>,int>>>& us,pair<int,int> a){
        pair<int,int> p = us[a.first][a.second].first;
        if(p.first == a.first && p.second == a.second){
            return p;
        }

        pair<int,int> pp = us[p.first][p.second].first;
        if(pp.first == p.first && pp.second == p.second){
            return pp;
        }
        us[p.first][p.second].second -= us[a.first][a.second].second;
        p = find(us,p);
        us[a.first][a.second].first = p;
        return us[a.first][a.second].first;

    }
    void uni(vector<vector<pair<pair<int,int>,int>>>& us,pair<int,int> a,pair<int,int> b){
        a = find(us,a);
        b = find(us,b);
        if(a.first == b.first && a.second == b.second){
            return ;
        }
        if(a.first > b.first){
            swap(a,b);
        }
        us[b.first][b.second].first = a;
        us[a.first][a.second].second +=  us[b.first][b.second].second;
        if(a.first==0 && b.first != 0){
            sums += us[b.first][b.second].second;
        }
    }
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        vector<vector<int>> tempgird = grid;

        int m = grid.size();
        int n = grid[0].size();
        int hitn = hits.size();
        for(int i = 0; i < hitn; i ++){
            grid[hits[i][0]][hits[i][1]] = 0;
        }
        vector<vector<int>> offset={
            {-1,0},
            {1,0},
            {0,-1},
            {0,1},
        };

        vector<vector<pair<pair<int,int>,int>>> us(m,vector<pair<pair<int,int>,int>>(n));
        sums = 0;
        for(int i = 0;i < m; i ++){
            for(int j = 0; j < n; j ++){
                us[i][j] = {{i,j},grid[i][j]};
                if(i == 0){sums += grid[i][j];}
            }
        }
        
        vector<int> o;
        for(int i = 0;i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(grid[i][j]==0){continue;}
                for(int k = 0; k < offset.size(); k ++){
                    o={i+offset[k][0],j+offset[k][1]};
                    if(o[0] >= 0 && o[0] < m && o[1]>=0 && o[1] < n && grid[o[0]][o[1]] == 1){
                        uni(us,{i,j},{o[0],o[1]});
                    }
                }
            }
        }
        vector<int> ret;
        
        ret.push_back(sums);
        pair<int,int> a;
        pair<int,int> b;
        for(int i = hitn - 1 ; i >= 0; i --){
            if(tempgird[hits[i][0]][hits[i][1]]==1){
                grid[hits[i][0]][hits[i][1]] = 1;
                us[hits[i][0]][hits[i][1]].second = 1;
                if(hits[i][0] == 0){
                    sums  ++;
                }
                for(int j = 0; j < 4; j ++){                
                    o={hits[i][0]+offset[j][0],hits[i][1]+offset[j][1]};
                    if(o[0] >= 0 && o[0] < m && o[1]>=0 && o[1] < n && grid[o[0]][o[1]] == 1){
                        a = find(us,{hits[i][0],hits[i][1]});
                        b = find(us,{o[0],o[1]});
                        uni(us,a,b);
                    }
                }
            }
            ret.push_back(sums);
        }
        reverse(ret.begin(),ret.end());
        vector<int> ans(hitn,0);
        for(int i = 0; i < hitn; i ++){
            ans[i] = max(0,ret[i] - ret[i+1] - 1);
        }
        return ans;
    }
};

// int main(){
//     vector<vector<int>> grid={
// {1,1,1},{0,1,0},{0,0,0}
//     };
//     vector<vector<int>> hits={
// {0,2},{2,0},{0,1},{1,2}
//     };

//     Solution solution;
//     auto ans = solution.hitBricks(grid,hits);
//     return 0;
// }