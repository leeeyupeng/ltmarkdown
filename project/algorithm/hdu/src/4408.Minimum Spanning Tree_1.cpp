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
    long long ans;

    vector<char> visit;
public:
    struct  Edge
    {
        int u;
        int v;
        int w;
        Edge():Edge(0,0,0){}
        Edge(int _u,int _v,int _w):u(_u),v(_v),w(_w){}
    };

    struct  Edge2
    {
        int v;
        int w;
        int next;
        Edge2():Edge2(0,0,-1){}
        Edge2(int _v,int _w,int _next):v(_v),w(_w),next(_next){}
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

    void dfs(vector<int> &vertice,vector<Edge2> &edges2,vector<char> &visit,int counter,int curmst,long long ret){
        if(counter == n-1 && curmst == this->minmst){
            ans += ret;
            ans = ans>=q?ans - q:ans;
            return;
        }
        if(counter == n-1){return;}
        if(curmst > this->minmst){return;}

        int edgeid;
        for(int i = 0; i < n; i ++){
            if(visit[i] == 0){
                visit[i] = 1;
                int count[11];
                for(int i = 0; i <=10; i ++){count[i] = 0;}
                edgeid = vertice[i];
                while(edgeid!=-1){
                    if( visit[edges2[edgeid].v] == 1){
                        count[edges2[edgeid].w]++;                        
                    }
                    edgeid = edges2[edgeid].next;
                }
                for(int c = 1; c <= 10; c ++){
                    if(count[c] > 0){
                        dfs(vertice,edges2,visit,counter + 1,curmst + c,ret * count[c]);
                    }
                }

                visit[i] = 0;
            }
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
        visit = vector<char>(n,0);
        vector<int> vertice(n,-1);
        vector<Edge2> edges2(m<<1);
        for(int i = 0; i < m; i ++){
            edges2[i<<1] = {edges[i].v,edges[i].w,vertice[edges[i].u]};
            vertice[edges[i].u] = i<<1;
            edges2[(i<<1)+1] = {edges[i].u,edges[i].w,vertice[edges[i].v]};
            vertice[edges[i].v] = (i<<1)+1;
        }
        visit[0] = 1;
        dfs(vertice,edges2,visit,0,0,1);
        return ans;
    }
    
};

// int main(){
//     int n,m,q;
//     while(scanf("%d%d%d",&n,&m,&q)!=EOF){
//         if(n==0 && m == 0 && q == 0){break;}
//         vector<Solution::Edge> edges(m);
//         for(int i = 0; i < m; i ++){            
//             edges[i].u = rand() % n;
//             edges[i].v = rand() % n;
//             edges[i].w = rand() % 10 + 1;
//             // scanf("%d%d%d",&edges[i].u,&edges[i].v,&edges[i].w);
//             // edges[i].u--;
//             // edges[i].v--;
//         }
//         Solution solution;
//         int ret = solution.Solve(n,m,q,edges);
//         printf("%d\n",ret);
//     }
//     return 0;
// }