#include"hdu.h"

class Solution{
private:
    vector<int> us;
    int find(int index){
        if(us[index] != index){
            us[index] = find(us[index]);
        }
        return us[index];
    }
    int n,m,q;
    int minmst;
    int ans;
public:
    struct  Edge
    {
        int u;
        int v;
        int w;
        Edge():Edge(0,0,0){}
        Edge(int _u,int _v,int _w):u(_u),v(_v),w(_w){}
    };

    int mst(vector<Edge> &edges){
        for(int i = 0; i < n; i ++){us[i] = i;}
        int ret = 0;
        int counter = 0;
        int up,vp;
        for(int i = 0; i < m; i ++){
            if(counter == n-1){
                break;
            }
            up = find(edges[i].u);
            vp = find(edges[i].v);
            if(up != vp){
                counter ++;
                us[vp] = up;
                ret += edges[i].w;
            }
        }
        return ret;
    }
    void dfs(vector<Edge> &edges,int index,int curmst,int sums,int counter){
        if(counter == n-1 && curmst == minmst){
            ans ++;
            ans = ans>=q?ans-q:ans;
            return;
        }
        if(counter>=n-1){return;}
        if(counter + m - index<n-1){return;}
        if(curmst>minmst){return;}
        if(curmst + sums > minmst){return;}
        int up = find(edges[index].u);
        int vp = find(edges[index].v);
        if(up!=vp){
            us[vp] = up;
            dfs(edges,index+1,curmst + edges[index].w,sums - edges[index].w,counter+1);
            us[vp] = vp;
        }
        if(index+(n-1-counter)<m){
            sums -= edges[index].w;
            sums += edges[index+(n-1-counter)].w;
            dfs(edges,index+1,curmst,sums,counter);
        }
    }
    int Solve(int n,int m,int q,vector<Edge> &edges){
        this->n = n;
        this->m = m;
        this->q = q;
        sort(edges.begin(),edges.end(),[](Edge &a,Edge &b){
            if(a.w == b.w){
                if(a.u == b.u){
                    return a.v < b.v;
                }
                return a.u < b.u;
            }
            return a.w < b.w;
        });
        us = vector<int>(n,0);

        this->minmst = mst(edges);
        int sums = 0;
        for(int i = 0 ; i < n-1; i ++){
            sums += edges[i].w;
        }
        ans = 0;
        for(int i = 0; i < n; i ++){us[i] = i;}
        dfs(edges,0,0,sums,0);
        return ans;
    }
    
};

// int main(){
//     int n,m,q;
//     while(scanf("%d%d%d",&n,&m,&q)!=EOF){
//         if(n==0 && m == 0 && q == 0){break;}
//         vector<Solution::Edge> edges(m);
//         for(int i = 0; i < m; i ++){            
//             // edges[i].u = rand() % n;
//             // edges[i].v = rand() % n;
//             // edges[i].w = rand() % 10 + 1;
//             scanf("%d%d%d",&edges[i].u,&edges[i].v,&edges[i].w);
//             edges[i].u--;
//             edges[i].v--;
//         }
//         Solution solution;
//         int ret = solution.Solve(n,m,q,edges);
//         printf("%d\n",ret);
//     }
//     return 0;
// }