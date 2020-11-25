#include"leetcode.h"

class Solution {
private:
    int m,n,introvertsCount,extrovertsCount;
    int halfm,halfn;

    int ans;
    inline int getHappinss(vector<int> &grid){
        int ans = 0;
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n;j ++){
                if(grid[i*n+j] == 0){
                    continue;
                }
                else if(grid[i*n+j] == -1){
                    ans+=120;
                    if(i>0 && grid[(i-1)*n+j]!=0){ans -= 30;}
                    if(i<m-1 && grid[(i+1)*n+j]!=0){ans -= 30;}
                    if(j>0 && grid[(i)*n+j-1]!=0){ans -= 30;}
                    if(j<n-1 && grid[(i)*n+j+1]!=0){ans -= 30;}
                }
                else if(grid[i*n+j] == 1){
                    ans+=40;
                    if(i>0 && grid[(i-1)*n+j]!=0){ans += 20;}
                    if(i<m-1 && grid[(i+1)*n+j]!=0){ans += 20;}
                    if(j>0 && grid[(i)*n+j-1]!=0){ans += 20;}
                    if(j<n-1 && grid[(i)*n+j+1]!=0){ans += 20;}
                }
            }
        }
        return ans;
    }
    void dfs(vector<int> &grid,char i,char j,char count1,char count2){
        if(count1 > introvertsCount || count2 > extrovertsCount){
            return;
        }

        if(i == m){
            int v = getHappinss(grid);
            if(v>ans){
                ans = v;
            }
            return;
        }
        if(count1 == introvertsCount && count2 == extrovertsCount){
            int v = getHappinss(grid);
            if(v>ans){
                ans = v;
            }
            return;
        }
        int value = (introvertsCount - count1+extrovertsCount - count2) * 120;
        if(value+getHappinss(grid) <= ans){return;}

        char ii = i,jj = j;
        if(j == n-1){
            ii = i +1;
            jj = 0;
        }
        else{
            ii= i;
            jj = j+1;
        }

        if(i > (this->halfm) && j > (this->halfn)){
            char op = (m-i-1)*n + (n-j-1);
            if(grid[op] == 0){
                grid[i*n+j]=-1;
                dfs(grid,ii,jj,count1+1,count2);
                grid[i*n+j]=0;
                dfs(grid,ii,jj,count1,count2);
            }
            else if(grid[op] == -1){                
                grid[i*n+j]=-1;
                dfs(grid,ii,jj,count1+1,count2);
                grid[i*n+j]=0;
                //dfs(grid,ii,jj,count1,count2);
            }
            else{  
                grid[i*n+j]=-1;
                dfs(grid,ii,jj,count1+1,count2);              
                grid[i*n+j]=1;
                dfs(grid,ii,jj,count1,count2+1);

                grid[i*n+j]=0;
                dfs(grid,ii,jj,count1,count2);
            }
        }
        else if(i > this->halfm){
            char op = (m-i-1)*n + j;
            if(grid[op] == 0){
                grid[i*n+j]=-1;
                dfs(grid,ii,jj,count1+1,count2);
                grid[i*n+j]=0;
                dfs(grid,ii,jj,count1,count2);
            }
            else if(grid[op] == -1){                
                grid[i*n+j]=-1;
                dfs(grid,ii,jj,count1+1,count2);
                grid[i*n+j]=0;
                //dfs(grid,ii,jj,count1,count2);
            }
            else{   
                grid[i*n+j]=-1;
                dfs(grid,ii,jj,count1+1,count2);             
                grid[i*n+j]=1;
                dfs(grid,ii,jj,count1,count2+1);

                grid[i*n+j]=0;
                dfs(grid,ii,jj,count1,count2);
            }
        }
        else if(j > (this->halfn)){
            char op = (i)*n + (n-j-1);
            if(grid[op] == 0){
                grid[i*n+j]=-1;
                dfs(grid,ii,jj,count1+1,count2);
                grid[i*n+j]=0;
                dfs(grid,ii,jj,count1,count2);
            }
            else if(grid[op] == -1){                
                grid[i*n+j]=-1;
                dfs(grid,ii,jj,count1+1,count2);
                grid[i*n+j]=0;
                //dfs(grid,ii,jj,count1,count2);
            }
            else{  
                grid[i*n+j]=-1;
                dfs(grid,ii,jj,count1+1,count2);              
                grid[i*n+j]=1;
                dfs(grid,ii,jj,count1,count2+1);
                
                grid[i*n+j]=0;
                dfs(grid,ii,jj,count1,count2);
            }
        }
        else
        {
            grid[i*n+j]=-1;
            dfs(grid,ii,jj,count1+1,count2);
            grid[i*n+j]=1;
            dfs(grid,ii,jj,count1,count2+1);            

            grid[i*n+j] = 0;
            dfs(grid,ii,jj,count1,count2);
        }
    }
public:
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        this->m = m;
        this->n = n;
        this->introvertsCount = introvertsCount;
        this->extrovertsCount = extrovertsCount;
        if(m&0x1 == 0x1){
            this->halfm = m>>1;
        }
        else{
            this->halfm = m>>1;
            this->halfm --;
        }
        if(n&0x1 == 0x1){
            this->halfn = n>>1;
        }
        else{
            this->halfn = n>>1;
            this->halfn --;
        }
        
        vector<int> grid(m*n);
        for(int i = 0; i < m*n; i ++){
            grid[i] = 0;
        }
        ans = 0;
        dfs(grid,0,0,0,0);
        return ans;
    }
};

// int main(){
//     Solution solution;
//     int m = 3;
//     int n = 4;
//     int introvertsCount = 4;
//     int extrovertsCount = 3;
    
//     int ans = solution.getMaxGridHappiness(m,n,introvertsCount,extrovertsCount);
//     return 0;
// }