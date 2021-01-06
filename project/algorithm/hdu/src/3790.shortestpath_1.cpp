#include"hdu.h"

struct EdgeNode{
    int t;
    int d;
    int p;
    EdgeNode* next;
    EdgeNode(int _t):t(_t),next(nullptr){}
};
class Solution{
private:
public:
    pair<int,int> shortestpath(vector<EdgeNode*>& vertice,vector<EdgeNode>& edges,int n,int m,int s,int t){
        auto cmp = [](pair<int,pair<int,int>>& a,pair<int,pair<int,int>>& b){
            if(a.second.first==b.second.first){
                if(a.second.second==b.second.second){
                    return a.first > b.first;
                }
                return a.second.second>b.second.second;
            }
            return a.second.first > b.second.first;
        };
        vector<char> visit(n+1,0);
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,decltype(cmp)> q(cmp);
        q.push({s,{0,0}});
        pair<int,pair<int,int>> top;
        EdgeNode* edge;
        while(!q.empty()){
            top = q.top();
            visit[top.first] = 1;
            q.pop();
            if(top.first == t){
                return top.second;
            }
            else{
                edge = vertice[top.first];
                while(edge!=nullptr){
                    if(visit[edge->t] == 0){
                        q.push({edge->t,{top.second.first + edge->d,top.second.second+edge->p}});
                    }
                    edge = edge->next;
                }
            }
        }
        return {0,0};
    }
};

// int main(){
//     int n,m;
//     Solution solution;
//     while(scanf("%d%d",&n,&m)){
//         if(n==0&&m==0){break;}
//         vector<EdgeNode*> vertice(n+1);
//         vector<EdgeNode> edges((m<<1),EdgeNode(0));
//         int s,t,d,p;
//         for(int i = 0; i < m; i ++){
//             scanf("%d%d%d%d",&s,&t,&d,&p);
//             edges[(i<<1)].t = t;
//             edges[(i<<1)].d = d;
//             edges[(i<<1)].p = p;
//             edges[(i<<1)].next = vertice[s];
//             vertice[s] = &edges[(i<<1)];
//             edges[(i<<1) + 1].t = s;
//             edges[(i<<1) + 1].d = d;
//             edges[(i<<1) + 1].p = p;
//             edges[(i<<1) + 1].next = vertice[t];
//             vertice[t]=&edges[(i<<1) + 1];
//         }
//         scanf("%d%d",&s,&t);
//         pair<int,int> ret = solution.shortestpath(vertice,edges,n,m,s,t);
//         printf("%d %d\n",ret.first,ret.second);
//     }
//     return 0;
// }