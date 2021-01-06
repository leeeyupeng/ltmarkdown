#include"hdu.h"

#define NMAX 1000
struct EdgeNode{
    int t;
    int time;
    EdgeNode* next;
    EdgeNode(int _t,int _time):t(_t),time(_time){}
};
class Solution{
private:
    int dijkstra(vector<EdgeNode*>& vertice,vector<EdgeNode>& edges,int s,vector<char>& vflagt){
        auto cmp = [](pair<int,int>& a,pair<int,int>& b){
            if(a.second==b.second){
                return a.first>b.first;
            }
            return a.second > b.second;
        };
        vector<char> visit(NMAX+1,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> q(cmp);
        q.push({s,0});
        pair<int,int> top;
        EdgeNode* edge;
        while(!q.empty()){
            top = q.top();
            visit[top.first] = 1;
            q.pop();
            if(vflagt[top.first]==1){
                return top.second;
            }
            else{
                edge = vertice[top.first];
                while(edge!=nullptr){
                    if(visit[edge->t] == 0){
                        q.push({edge->t,top.second + edge->time});
                    }
                    edge = edge->next;
                }
            }
        }
        return -1;
    }
public:
    int solve(int t,int s,int d,vector<EdgeNode*>& vertice,vector<EdgeNode>& edges,vector<int>& vs,vector<int>& vd){
        for(int i = 0; i < s; i ++){
            for(int j = 0;j < d; j ++){
                if(vs[i] == vd[j]){return 0;}
            }
        }
        vector<char> vdflag(NMAX+1,0);
        for(int i = 0; i < d; i ++){
            if(vd[i] <= NMAX){
                vdflag[vd[i]] = 1;
            }
        }
        int ret = -1;
        int temp;
        for(int i = 0; i < s; i ++){
            temp = dijkstra(vertice,edges,vs[i],vdflag);
            if(temp == -1){continue;}
            else if(ret == -1){ret = temp;}
            else if(ret > temp){ret = temp;}
        }
        return ret;
    }
};
// int main(){
//     int t,s,d;
//     int a,b,time;
//     Solution solution;
//     while(scanf("%d%d%d",&t,&s,&d)!=EOF){
//         vector<EdgeNode*> vertice(NMAX + 1,nullptr);
//         vector<EdgeNode> edges((t<<1),{0,0});
//         for(int i = 0; i < t; i ++){
//             scanf("%d%d%d",&a,&b,&time);
//             edges[(i<<1)].t = b;
//             edges[(i<<1)].time = time;
//             edges[(i<<1)].next = vertice[a];
//             vertice[a] = &edges[(i<<1)];

//             edges[(i<<1)+1].t = a;
//             edges[(i<<1)+1].time =time;
//             edges[(i<<1)+1].next = vertice[b];
//             vertice[b] = &edges[(i<<1)+1];
//         }

//         vector<int> vs(s);
//         for(int i = 0; i < s; i ++){
//             scanf("%d",&vs[i]);
//         }
//         vector<int> vd(d);
//         for(int i = 0; i < d; i ++){
//             scanf("%d",&vd[i]);
//         }

//         int ret = solution.solve(t,s,d,vertice,edges,vs,vd);
//         printf("%d\n",ret);
//     }
// }