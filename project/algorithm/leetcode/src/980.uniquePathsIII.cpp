#include"leetcode.h"

class Solution {
private:
    int m,n;
    int startx,starty;
    int endx,endy;
    int ans;
    void dfs(vector<vector<int>>& grid,vector<vector<char>>& visit,int x,int y,int counter){
        if(counter == 0){
            if(x-1==endx && y == endy){
                ans++;
            }
            else if(x+1 == endx && y == endy){
                ans++;
            }
            else if(x == endx && y-1 == endy){
                ans++;
            }
            else if(x == endx && y+1 == endy){
                ans ++;
            }
            return;
        }
        visit[x][y] = 1;
        if(x>0&&grid[x-1][y]==0 && visit[x-1][y] == 0){
            dfs(grid,visit,x-1,y,counter-1);
        }
        if(x<m-1&&grid[x+1][y]==0 && visit[x+1][y] == 0){
            dfs(grid,visit,x+1,y,counter-1);
        }

        if(y>0&&grid[x][y-1]==0 && visit[x][y-1] == 0){
            dfs(grid,visit,x,y-1,counter-1);
        }
        if(y<n-1&&grid[x][y+1]==0 && visit[x][y+1] == 0){
            dfs(grid,visit,x,y+1,counter-1);
        }
        visit[x][y] = 0;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int counter = 0;
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(grid[i][j] == 0){
                    counter++;
                }
                else if(grid[i][j] == 1){
                    startx = i;
                    starty = j;
                }
                else if(grid[i][j] == 2){
                    endx = i;
                    endy = j;
                }
            }
        }
        ans = 0;
        vector<vector<char>> visit(m,vector<char>(n,0));
        dfs(grid,visit,startx,starty,counter);
        return ans;
    }
};

// int main(){
//     Solution solution;
//     vector<vector<int>> grid={
//         {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//         {0,0,2,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
//     };

//     int ans = solution.uniquePathsIII(grid);

//     return 0;
// }