#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include<limits.h>

#include <cstdio>
#include <cstring>

using namespace std;

struct Edge{
    int a;
    int b;
    int d;
    int next;
    Edge(int _a,int _b,int _d):a(_a),b(_b),d(_d),next(-1){}
};

class Solution{
private:
    int n,r;
    int s,t;
    vector<int> distance1;
    vector<int> distance2;
    void spfa(vector<int>& vertice,vector<Edge>& edge){
        queue<int> q;
        q.push(s);
        int curvertice;
        int edgeid;
        bool flag = false;
        vector<char> ishasinqueue(n+1,0);
        ishasinqueue[s] = 1;
        while(!q.empty()){
            curvertice = q.front();
            q.pop();
            ishasinqueue[curvertice] = 0;
            edgeid = vertice[curvertice];
            while(edgeid!=-1){
                flag = false;
                if(distance1[edge[edgeid].b] > distance1[curvertice] + edge[edgeid].d){
                    distance2[edge[edgeid].b] = distance1[edge[edgeid].b];
                    distance1[edge[edgeid].b] = distance1[curvertice] + edge[edgeid].d;
                    flag = true;
                }
                if(distance2[curvertice]!=INT_MAX && distance2[edge[edgeid].b] > distance2[curvertice] + edge[edgeid].d)
                {
                    distance2[edge[edgeid].b] = distance2[curvertice] + edge[edgeid].d;
                    flag = true;
                }
                if(distance1[edge[edgeid].b] < distance1[curvertice] + edge[edgeid].d){
                    if(distance2[edge[edgeid].b] >distance1[curvertice] + edge[edgeid].d){
                       distance2[edge[edgeid].b] =distance1[curvertice] + edge[edgeid].d;
                       flag = true;
                    }
                }
                if(flag==true && ishasinqueue[edge[edgeid].b] == 0){q.push(edge[edgeid].b);ishasinqueue[edge[edgeid].b] = 1;}
                edgeid = edge[edgeid].next;
            }
        }
    }
public:
    int solve(int n,int r,vector<int>& vertice,vector<Edge>& edge,int s,int t){
        this->n = n;
        this->r = r;
        this->s = s;
        this->t = t;
        distance1 = vector<int>(n+1,INT_MAX);
        distance2 = vector<int>(n+1,INT_MAX);
        distance1[s] = 0;
        //distance2[s] = 0;

        spfa(vertice,edge);
        return distance2[t];
    }
};

// int main()
// {
//     int n,r;
//     int a,b,d;
//     while(scanf("%d%d",&n,&r)!=EOF)
//     {
//         vector<int> vertice(n+1,-1);
//         vector<Edge> edge(r<<1,{0,0,0});
//         for(int i = 0; i < r; i ++){
//             scanf("%d%d%d",&a,&b,&d);
//             edge[i<<1] = {a,b,d};
//             edge[i<<1].next = vertice[a];
//             vertice[a] = i<<1;

//             edge[(i<<1) | 0x1] = {b,a,d};
//             edge[(i<<1) | 0x1].next = vertice[b];
//             vertice[b] = (i<<1) | 0x1;
//         }

//         Solution solution;
//         int ret = solution.solve(n,r,vertice,edge,1,n);      
//         printf("%d\n",ret);
//     }
//     return 0;
// }