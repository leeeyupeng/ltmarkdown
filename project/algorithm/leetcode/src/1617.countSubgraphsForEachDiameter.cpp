#include"leetcode.h"

#define DISTANCEMAX 100
class Solution {
private:
    vector<int> vus;
    void USUnion(int a,int b){
        vus[USParent(a)]=USParent(b);
    }
    bool USIsUnion(int a,int b){
        return USParent(a) == USParent(b);
    }
    int USParent(int a){
        if(vus[a] == a){return a;}
        vus[a]=USParent(vus[a]);
        return vus[a];
    }

    vector<vector<int>> dist;
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vus = vector<int>(n);
        for(int i = 0; i < n; i ++){
            vus[i] = i;
        }

        dist = vector<vector<int>>(n,vector<int>(n));
        // for(int i = 0; i < n; i ++){
        //     dist[i][i] = 0;
        //     for(int j = 0; j <n; j ++){
        //         dist[i][j]=DISTANCEMAX;
        //     }
        // }
        for(int i = 0; i < n-1; i ++){
            edges[i][0] --;
            edges[i][1] --;
        }
        // for(int i = 0; i < n-1; i ++){
        //     dist[edges[i][0]][edges[i][1]] = 1;
        //     dist[edges[i][1]][edges[i][0]] = 1;
        // }
        // for(int k = 0; k < n; k ++){
        //     for(int i = 0; i < n; i ++){
        //         for(int j = 0; j < n;j ++){
        //             dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
        //         }
        //     }
        // }
 
        vector<int> vans(n-1);
        for(int i = 0; i < n-1; i ++){
            vans[i] = 0;
        }
        int parent=-1;
        bool flagUnion= true;
        int maxdist=0;
        for(int k = 1; k < (1<<n);k++){
            for(int i = 0; i < n; i ++){
                vus[i] = i;
            }
            for(int i = 0; i < n-1; i ++){
                if((k>>edges[i][0])&0x1 == 0x1 && (k>>edges[i][1])&0x1 == 0x1){
                    USUnion(edges[i][0],edges[i][1]);
                }
            }
            parent=-1;
            flagUnion= true;
            for(int i = 0; i < n; i ++){
                if((k>>i)&0x1 == 0x1){
                    if(parent == -1){
                        parent = USParent(i);
                    }
                    else{
                        if(parent != USParent(i)){
                            //不连通
                            flagUnion = false;
                        }
                    }
                }
            }
            if(flagUnion==true){
                maxdist = 0;
                for(int i = 0; i < n; i ++){
                    for(int j = 0; j <n; j ++){
                        dist[i][j]=DISTANCEMAX;
                    }
                    dist[i][i] = 0;
                }
                for(int i = 0; i < n-1; i ++){
                    if((k>>edges[i][0])&0x1 == 0x1 && (k>>edges[i][1])&0x1 == 0x1){
                        dist[edges[i][0]][edges[i][1]] = 1;
                        dist[edges[i][1]][edges[i][0]] = 1;
                    }
                }
                for(int d = 0; d < n; d ++){
                    if((k>>d)&0x1 == 0x1){
                        for(int i = 0; i < n; i ++){
                            if((k>>i)&0x1 == 0x1){
                                for(int j = 0; j < n;j ++){
                                    if((k>>j)&0x1 == 0x1){
                                        dist[i][j] = min(dist[i][j],dist[i][d]+dist[d][j]);
                                    }
                                }
                            }
                        }
                    }
                }
                for(int i = 0; i < n; i ++){
                    if((k>>i)&0x1 == 0x1){
                        for(int j = i+1;j < n; j ++){
                            if((k>>j)&0x1 == 0x1){
                                maxdist = max(maxdist,dist[i][j]);
                            }
                        }
                    }
                }

                if(maxdist > 0){
                    vans[maxdist-1]++;
                }
            }
        }

        return vans;
    }
};

// int main(){
//     Solution solution;
//     int n = 4;
//     vector<vector<int>> edges={
// {1,2},{2,3},{2,4}
//     };
//     solution.countSubgraphsForEachDiameter(n,edges);
//     return 0;
// }