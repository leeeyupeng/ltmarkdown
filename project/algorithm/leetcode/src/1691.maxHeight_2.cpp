#include"leetcode.h"

#define MAX 100
class Solution {
private:
    int n;
    int ans;
    vector<int> vm;
    vector<int> vh;
    vector<unordered_map<int,int>> vmap;
    inline void initmap(vector<vector<int>>& cuboids,vector<unordered_map<int,int>>& vmap){
        int w,l,h;
        int key;
        for(int i = 0; i < n; i ++){
            w = 0,l = 1;h = 2;
            key = cuboids[i][w] * MAX * MAX+cuboids[i][l] * MAX+cuboids[i][h];
            if(vmap[i].find(key) == vmap[i].end()){
                vmap[i][key] = 0;
            }
            vmap[i][key] = max(vmap[i][key],cuboids[i][h]);
            w = 1,l = 0;h = 2;
            key = cuboids[i][w] * MAX * MAX+cuboids[i][l] * MAX+cuboids[i][h];
            if(vmap[i].find(key) == vmap[i].end()){
                vmap[i][key] = 0;
            }
            vmap[i][key] = max(vmap[i][key],cuboids[i][h]);
            w = 0,l = 2;h = 1;
            key = cuboids[i][w] * MAX * MAX+cuboids[i][l] * MAX+cuboids[i][h];
            if(vmap[i].find(key) == vmap[i].end()){
                vmap[i][key] = 0;
            }
            vmap[i][key] = max(vmap[i][key],cuboids[i][h]);
            w = 2,l = 0;h = 1;
            key = cuboids[i][w] * MAX * MAX+cuboids[i][l] * MAX+cuboids[i][h];
            if(vmap[i].find(key) == vmap[i].end()){
                vmap[i][key] = 0;
            }
            vmap[i][key] = max(vmap[i][key],cuboids[i][h]);
            w = 1,l = 2;h = 0;
            key = cuboids[i][w] * MAX * MAX+cuboids[i][l] * MAX+cuboids[i][h];
            if(vmap[i].find(key) == vmap[i].end()){
                vmap[i][key] = 0;
            }
            vmap[i][key] = max(vmap[i][key],cuboids[i][h]);
            w = 2,l = 1;h = 0;
            key = cuboids[i][w] * MAX * MAX+cuboids[i][l] * MAX+cuboids[i][h];
            if(vmap[i].find(key) == vmap[i].end()){
                vmap[i][key] = 0;
            }
            vmap[i][key] = max(vmap[i][key],cuboids[i][h]);
        }
    }
    inline void initvh(vector<unordered_map<int,int>>& vmap,vector<int>& vh){
        for(int i = 0; i < n; i ++){
            for(unordered_map<int,int>::iterator ite = vmap[i].begin();ite!=vmap[i].end();ite++){
                vh[ite->first]+=ite->second;
            }
        }
    }
    inline void addvh(vector<unordered_map<int,int>>& vmap,vector<int>& vh,int index){
        int w,l,h;
        int i = index;
        {
            for(unordered_map<int,int>::iterator ite = vmap[i].begin();ite!=vmap[i].end();ite++){
                vh[ite->first]+=ite->second;
            }
        }
    }
    inline void removevh(vector<unordered_map<int,int>>& vmap,vector<int>& vh,int index){
        int w,l,h;
        int i = index;
        {
            for(unordered_map<int,int>::iterator ite = vmap[i].begin();ite!=vmap[i].end();ite++){
                vh[ite->first]-=ite->second;
            }
        }
    }
    inline int geth(vector<vector<int>>& cuboids,vector<char>& visit,int wrect,int lrect,int hrect){
        int sums = 0;
        int maxh;
        int w,l,h;
        for(int i = 0; i < n; i ++){
            if(visit[i]==0){
                maxh = 0;
                w = 0,l = 1;h = 2;
                if(wrect==cuboids[i][w]&&lrect==cuboids[i][l]&&hrect>=cuboids[i][h]){
                    maxh = max(maxh,cuboids[i][h]);
                }
                w = 1,l = 0;h = 2;
                if(wrect==cuboids[i][w]&&lrect==cuboids[i][l]&&hrect>=cuboids[i][h]){
                    maxh = max(maxh,cuboids[i][h]);
                }
                w = 0,l = 2;h = 1;
                if(wrect==cuboids[i][w]&&lrect==cuboids[i][l]&&hrect>=cuboids[i][h]){
                    maxh = max(maxh,cuboids[i][h]);
                }
                w = 2,l = 0;h = 1;
                if(wrect==cuboids[i][w]&&lrect==cuboids[i][l]&&hrect>=cuboids[i][h]){
                    maxh = max(maxh,cuboids[i][h]);
                }
                w = 1,l = 2;h = 0;
                if(wrect==cuboids[i][w]&&lrect==cuboids[i][l]&&hrect>=cuboids[i][h]){
                    maxh = max(maxh,cuboids[i][h]);
                }
                w = 2,l = 1;h = 0;
                if(wrect==cuboids[i][w]&&lrect==cuboids[i][l]&&hrect>=cuboids[i][h]){
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
    void dfs(vector<vector<int>>& cuboids,vector<char>& visit,int wrect,int lrect,int hrect,int sums){
        ans = max(ans,sums);
        int key = wrect * MAX * MAX + lrect * MAX + hrect;
        if(vm[key] > sums + vh[key]){return;}
        else{
            vm[key] = max(vm[key],sums);
        }

        // if(vm[wrect][lrect] >= sums){return;}
        // else{
        //     vm[wrect][lrect] = max(vm[wrect][lrect],sums);
        // }

        // int recth = geth(cuboids,visit,wrect,lrect);
        // if(vm[wrect][lrect] > sums + recth){return;}
        // else{
        //     vm[wrect][lrect] = max(vm[wrect][lrect],sums);
        // }
        
        //if(sums + getmaxsums(cuboids,visit,wrect,lrect) <= ans){return;}

        int w,l,h;
        bool flag = false;
        for(int i = 0; i < n; i ++){
            if(visit[i] == 0){
                visit[i] = 1;
                removevh(vmap,vh,i);
                w = 0,l = 1;h = 2;               
                if(wrect >= cuboids[i][w] && lrect >= cuboids[i][l] && hrect>=cuboids[i][h]){           
                    dfs(cuboids,visit,cuboids[i][w],cuboids[i][l],cuboids[i][h],sums + cuboids[i][h]);      
                }
                w = 1,l = 0;h = 2;
                if(wrect >= cuboids[i][w] && lrect >= cuboids[i][l] && hrect>=cuboids[i][h]){         
                    dfs(cuboids,visit,cuboids[i][w],cuboids[i][l],cuboids[i][h],sums + cuboids[i][h]);             
                }
                w = 0,l = 2;h = 1;
                if(wrect >= cuboids[i][w] && lrect >= cuboids[i][l] && hrect>=cuboids[i][h]){             
                    dfs(cuboids,visit,cuboids[i][w],cuboids[i][l],cuboids[i][h],sums + cuboids[i][h]);        
                }
                w = 2,l = 0;h = 1;
                if(wrect >= cuboids[i][w] && lrect >= cuboids[i][l] && hrect>=cuboids[i][h]){           
                    dfs(cuboids,visit,cuboids[i][w],cuboids[i][l],cuboids[i][h],sums + cuboids[i][h]);     
                }
                w = 1,l = 2;h = 0;
                if(wrect >= cuboids[i][w] && lrect >= cuboids[i][l] && hrect>=cuboids[i][h]){            
                    dfs(cuboids,visit,cuboids[i][w],cuboids[i][l],cuboids[i][h],sums + cuboids[i][h]);         
                }
                w = 2,l = 1;h = 0;
                if(wrect >= cuboids[i][w] && lrect >= cuboids[i][l] && hrect>=cuboids[i][h]){           
                    dfs(cuboids,visit,cuboids[i][w],cuboids[i][l],cuboids[i][h],sums + cuboids[i][h]);                              
                }
                visit[i] = 0;
                addvh(vmap,vh,i);
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
        vmap = vector<unordered_map<int,int>>(n);
        vm = vector<int>(MAX * MAX * MAX + MAX * MAX + MAX + 1,-1);
        vh = vector<int>(MAX * MAX * MAX + MAX * MAX + MAX + 1,0);
        // for(int i = 0; i <= 100; i ++){
        //     for(int j = 0; j <= 100;j ++){
        //         for(int z = 0; z <= 100; z++){
        //             vh[i][j][z] = geth(cuboids,visit,i,j,z);
        //         }
        //     }
        // }
        initmap(cuboids,vmap);
        initvh(vmap,vh);
        dfs(cuboids,visit,100,100,100,0);
        return ans;
    }
};

// int main(){
//     vector<vector<int>> cuboids={
// {13,82,63},{86,27,31},{96,75,81},{6,77,53},{86,59,83},{68,76,7},{86,40,40},{72,20,13},{6,63,31},{69,87,40},{88,1,33},{88,89,60},{84,10,2},{90,61,38},{13,95,28},{5,24,48},{18,59,72},{65,80,78},{26,64,45},{16,45,29},{83,94,86},{21,98,7},{3,3,88},{60,45,52},{25,78,32},{48,65,65},{78,18,93},{71,61,24},{41,89,15},{44,26,70},{62,85,1},{12,63,41},{5,78,9},{65,75,22},{74,12,54},{84,14,47},{54,55,91},{43,69,46},{39,55,21},{31,80,28},{5,52,82},{70,79,38},{48,90,70},{35,23,62},{66,80,62},{6,85,35},{88,70,79},{62,49,37},{57,59,95},{28,50,96},{54,10,49},{38,56,25},{40,52,54},{7,65,76},{100,9,26},{68,77,83},{73,58,81},{86,60,72},{1,17,17},{90,74,5},{87,100,12},{74,63,48},{27,2,79},{38,30,49},{65,32,38},{30,83,11}
//     };
//     // cuboids.clear();
//     // for(int i = 0; i < 100; i ++){
//     //     cuboids.push_back({rand() % 100,rand() % 100,rand() % 100});
//     // }
//     Solution solution;
//     int ret = solution.maxHeight(cuboids);
//     return 0;
// }