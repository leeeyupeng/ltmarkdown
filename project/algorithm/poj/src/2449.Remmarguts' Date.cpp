#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

struct Edge{
    int a;
    int b;
    int time;
    int next;
    Edge(int _a,int _b,int _time):a(_a),b(_b),time(_time),next(-1){}
};
class Solution{
private:
    int n,m;
    int s,t,k;
    vector<int> distance;
    void bellman_ford(vector<Edge>& edge){
        bool flag = true;
        for(int i = 0; i < n; i ++){
            if(flag == false){break;}
            flag = false;
            for(int j = 0;j < m;j ++){
                if(distance[edge[j].b]!=-1){
                    if(distance[edge[j].a] == -1){
                        distance[edge[j].a] = distance[edge[j].b] + edge[j].time;
                        flag = true;
                    }
                    else if(distance[edge[j].a] > distance[edge[j].b] + edge[j].time){
                        distance[edge[j].a] = distance[edge[j].b] + edge[j].time;
                        flag = true;
                    }
                }
            }
        }
    }

    int astar(vector<int>& vertice,vector<Edge>& edge){
        auto cmp=[](pair<int,pair<int,int>>& a,pair<int,pair<int,int>>& b){
            if(a.second.first + a.second.second == b.second.first + b.second.second){
                return a.first>b.first;
            }
            return a.second.first + a.second.second > b.second.first + b.second.second;
        };
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,decltype(cmp)> pq(cmp);
        int edgeid = vertice[s];
        while (edgeid!= -1)
        {
            pq.push({edge[edgeid].b,{edge[edgeid].time,distance[edge[edgeid].b]}});
            edgeid = edge[edgeid].next;
        }
        
        int kk = 0;
        pair<int,pair<int,int>> top;
        while(!pq.empty()){
            top = pq.top();
            pq.pop();
            kk++;
            if(kk == k){
                return top.second.first + top.second.second;
            }

            edgeid = vertice[top.first];
            while (edgeid!= -1)
            {
                pq.push({edge[edgeid].b,{top.second.first + edge[edgeid].time,distance[edge[edgeid].b]}});
                edgeid = edge[edgeid].next;
            }
        }

        return -1;
    }
public:
    int Solve(int n,int m,vector<int>& vertice,vector<Edge>& edge,int s,int t,int k){
        this->n = n;
        this->m = m;

        this->s = s;
        this->t = t;
        this->k = k;

        this->distance= vector<int>(this->n + 1,-1);
        this->distance[t] = 0;

        bellman_ford(edge);

        return astar(vertice,edge);
    }
};

// int main(){
//     int n,m;
    
//     while(scanf("%d%d",&n,&m)){
//         vector<int> vertice(n+1,-1);
//         vector<Edge> edge(m,{0,0,0});
//         int a,b,time;
//         for(int i = 0; i < m; i ++){
//             scanf("%d%d%d",&a,&b,&time);
//             // a = rand() % n;
//             // b = rand()% n;
//             // time = rand() % 100000;
//             edge[i] = {a,b,time};
//             edge[i].next = vertice[a];
//             vertice[a] = i;
//         }
//         int s,t,k;
//         scanf("%d%d%d",&s,&t,&k);

//         Solution solution;
//         int ret = solution.Solve(n,m,vertice,edge,s,t,k);      
//         printf("%d\n",ret);
//     }
//     return 0;
// }