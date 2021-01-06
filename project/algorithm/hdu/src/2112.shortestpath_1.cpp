#include"hdu.h"

#define CHARNUMS 256
#define VERTICEMAX 152
#define MAXLENGTH 32
class Solution{
public:
    struct  Edge
    {
        int e;
        int t;
        int next;

        Edge():e(0),t(0),next(-1){}
    };

    int getshotestpath(vector<int>& vertice, vector<Edge>& edges,int start,int end){
        auto cmp = [](pair<int,int>& a,pair<int,int>& b){
            if(a.second == b.second){
                return a.first > b.first;
            }

            return a.second > b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
        pq.push({start,0});

        vector<char> visit(VERTICEMAX,0);
        pair<int,int> top;
        while(!pq.empty()){
            top = pq.top();
            pq.pop();
            visit[top.first] = 1;
            if(top.first == end){
                return top.second;
            }

            int edgeid = vertice[top.first];

            while(edgeid != -1){
                if(visit[edges[edgeid].e] == 0)
                {
                    pq.push({edges[edgeid].e,top.second + edges[edgeid].t});
                }

                edgeid = edges[edgeid].next;
            }
        }

        return -1;
    }
};
// int main()
// {
//     int n;
//     while(scanf("%d",&n)!=EOF){
//         if(n==-1){break;}
        
//         Solution solution;

//         int cnt = 0;
//         map<string,int> map;
//         string start,end;
//         // start.resize(MAXLENGTH);
//         // end.resize(MAXLENGTH);
//         cin>>start>>end;
        
//         //scanf("%s%s",&start[0],&end[0]);
//         if(map.find(start) == map.end()){map.insert({start,cnt++});}
//         if(map.find(end) == map.end()){map.insert({end,cnt++});}
//         int startid = map[start];
//         int endid = map[end];

//         vector<int> vertice(VERTICEMAX,-1);
//         vector<Solution::Edge> edges(n<<1);
        
//         int t;
//         // s.resize(MAXLENGTH);
//         // e.resize(MAXLENGTH);
//         int sid;
//         int eid;
//         for(int i = 0; i < n; i ++){ 
//             string s,e;              
//             cin>>s>>e>>t;        
//             //scanf("%s%s%d",&s[0],&e[0],&t);
//             if(map.find(s) == map.end()){map.insert({s,cnt++});}
//             if(map.find(e) == map.end()){map.insert({e,cnt++});}
//             sid = map[s];
//             eid = map[e];

//             edges[i<<1].e = eid;
//             edges[i<<1].t = t;
//             edges[i<<1].next = vertice[sid];
//             vertice[sid] = i<<1;

//             edges[(i<<1) + 1].e = sid;
//             edges[(i<<1)+1].t = t;
//             edges[(i<<1) + 1].next = vertice[eid];
//             vertice[eid] = (i<<1)+1;
//         }
//         int ret = solution.getshotestpath(vertice,edges,startid,endid);

//         printf("%d\n",ret);
//     }
//     return 0;
// }