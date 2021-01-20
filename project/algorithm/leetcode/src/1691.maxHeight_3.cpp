#include"leetcode.h"

#define MAX 100
class Solution {
private:
    int n;
    int ans;
    vector<vector<int>> vm;
    vector<vector<int>> vh;
    inline int geth(vector<vector<int>>& cuboids,vector<char>& visit,int wrect,int lrect){
        int sums = 0;
        int maxh;
        int w,l,h;
        for(int i = 0; i < n; i ++){
            if(visit[i]==0){
                maxh = 0;
                w = 0,l = 1;h = 2;
                if(wrect==cuboids[i][w]&&lrect==cuboids[i][l]){
                    maxh = max(maxh,cuboids[i][h]);
                }
                w = 1,l = 0;h = 2;
                if(wrect==cuboids[i][w]&&lrect==cuboids[i][l]){
                    maxh = max(maxh,cuboids[i][h]);
                }
                w = 0,l = 2;h = 1;
                if(wrect==cuboids[i][w]&&lrect==cuboids[i][l]){
                    maxh = max(maxh,cuboids[i][h]);
                }
                w = 2,l = 0;h = 1;
                if(wrect==cuboids[i][w]&&lrect==cuboids[i][l]){
                    maxh = max(maxh,cuboids[i][h]);
                }
                w = 1,l = 2;h = 0;
                if(wrect==cuboids[i][w]&&lrect==cuboids[i][l]){
                    maxh = max(maxh,cuboids[i][h]);
                }
                w = 2,l = 1;h = 0;
                if(wrect==cuboids[i][w]&&lrect==cuboids[i][l]){
                    maxh = max(maxh,cuboids[i][h]);
                }
                sums += maxh;
            }
        }
        return sums;
    }
    inline int getmaxsums(vector<vector<int>>& cuboids,vector<char>& visit,int wrect,int lrect){
        int sums = 0;
        int maxh;
        int w,l,h;
        for(int i = 0; i < n; i ++){
            if(visit[i]==0){
                maxh = 0;
                w = 0,l = 1;h = 2;
                if(wrect>=cuboids[i][w]&&lrect>=cuboids[i][l]){
                    maxh = max(maxh,cuboids[i][h]);
                }
                w = 1,l = 0;h = 2;
                if(wrect>=cuboids[i][w]&&lrect>=cuboids[i][l]){
                    maxh = max(maxh,cuboids[i][h]);
                }
                w = 0,l = 2;h = 1;
                if(wrect>=cuboids[i][w]&&lrect>=cuboids[i][l]){
                    maxh = max(maxh,cuboids[i][h]);
                }
                w = 2,l = 0;h = 1;
                if(wrect>=cuboids[i][w]&&lrect>=cuboids[i][l]){
                    maxh = max(maxh,cuboids[i][h]);
                }
                w = 1,l = 2;h = 0;
                if(wrect>=cuboids[i][w]&&lrect>=cuboids[i][l]){
                    maxh = max(maxh,cuboids[i][h]);
                }
                w = 2,l = 1;h = 0;
                if(wrect>=cuboids[i][w]&&lrect>=cuboids[i][l]){
                    maxh = max(maxh,cuboids[i][h]);
                }
                sums += maxh;
            }
        }
        return sums;
    }
    void dfs(vector<vector<int>>& cuboids,vector<char>& visit,int wrect,int lrect,int sums){
        if(vm[wrect][lrect] > sums + vh[wrect][lrect]){return;}
        else{
            vm[wrect][lrect] = max(vm[wrect][lrect],sums + vh[wrect][lrect]);
        }

        // if(vm[wrect][lrect] >= sums){return;}
        // else{
        //     vm[wrect][lrect] = max(vm[wrect][lrect],sums);
        // }

        // int recth = geth(cuboids,visit,wrect,lrect);
        // if(vm[wrect][lrect] > sums + recth){return;}
        // else{
        //     vm[wrect][lrect] = max(vm[wrect][lrect],sums + recth);
        // }
        
        //if(sums + getmaxsums(cuboids,visit,wrect,lrect) <= ans){return;}

        int w,l,h;
        ans = max(ans,sums);
        bool flag = false;
        for(int i = 0; i < n; i ++){
            if(visit[i] == 0){
                visit[i] = 1;
                w = 0,l = 1;h = 2; 
                vh[cuboids[i][w]][cuboids[i][l]]-= cuboids[i][h]; 
                w = 1,l = 0;h = 2; 
                vh[cuboids[i][w]][cuboids[i][l]]-= cuboids[i][h]; 
                w = 0,l = 2;h = 1; 
                vh[cuboids[i][w]][cuboids[i][l]]-= cuboids[i][h]; 
                w = 2,l = 0;h = 1; 
                vh[cuboids[i][w]][cuboids[i][l]]-= cuboids[i][h]; 
                w = 1,l = 2;h = 0; 
                vh[cuboids[i][w]][cuboids[i][l]]-= cuboids[i][h]; 
                w = 2,l = 1;h = 0;              
                if(wrect >= cuboids[i][w] && lrect >= cuboids[i][l]){         
                    dfs(cuboids,visit,cuboids[i][w],cuboids[i][l],sums + cuboids[i][h]);            
                }
                w = 1,l = 0;h = 2;
                if(wrect >= cuboids[i][w] && lrect >= cuboids[i][l]){         
                    dfs(cuboids,visit,cuboids[i][w],cuboids[i][l],sums + cuboids[i][h]);   
                }
                w = 0,l = 2;h = 1;
                if(wrect >= cuboids[i][w] && lrect >= cuboids[i][l]){       
                    dfs(cuboids,visit,cuboids[i][w],cuboids[i][l],sums + cuboids[i][h]);   
                }
                w = 2,l = 0;h = 1;
                if(wrect >= cuboids[i][w] && lrect >= cuboids[i][l]){       
                    dfs(cuboids,visit,cuboids[i][w],cuboids[i][l],sums + cuboids[i][h]);   
                }
                w = 1,l = 2;h = 0;
                if(wrect >= cuboids[i][w] && lrect >= cuboids[i][l]){    
                    dfs(cuboids,visit,cuboids[i][w],cuboids[i][l],sums + cuboids[i][h]);   
                }
                w = 2,l = 1;h = 0;
                if(wrect >= cuboids[i][w] && lrect >= cuboids[i][l]){     
                    dfs(cuboids,visit,cuboids[i][w],cuboids[i][l],sums + cuboids[i][h]);   
                }
                visit[i] = 0;
            }
        }
    }
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        n = cuboids.size();
        sort(cuboids.begin(),cuboids.end(),[](vector<int> &a,vector<int> &b){
            if(a[0]+a[1] + a[2] == b[0] + b[1] + b[2]){
                if(a[0]!=b[0]){
                    return a[0]<b[0];
                }
                if(a[1]!=b[1]){
                    return a[1]<b[1];
                }
            }
            return a[0]+a[1] + a[2] > b[0] + b[1] + b[2];
        });
        vector<char> visit(n,0);
        ans = 0;
        vm = vector<vector<int>>(100+1,vector<int>(100 + 1,-1));
        vh = vector<vector<int>>(100+1,vector<int>(100 + 1,0));
        for(int i = 0; i <= 100; i ++){
            for(int j = 0; j <= 100;j ++){
                vh[i][j] = geth(cuboids,visit,i,j);
            }
        }
        dfs(cuboids,visit,100,100,0);
        return ans;
    }
};

// int main(){
//     vector<vector<int>> cuboids={
// {95,37,53},{50,45,20},{45,23,12}
//     };
//     cuboids.clear();
//     for(int i = 0; i < 100; i ++){
//         cuboids.push_back({rand() % 100,rand() % 100,rand() % 100});
//     }
//     Solution solution;
//     int ret = solution.maxHeight(cuboids);
//     return 0;
// }