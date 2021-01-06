#include"hdu.h"

#define CHARNUMS 256
#define VERTICEMAX 152
#define MAXLENGTH 32
class Solution{
    struct TrieNode{
        int index;
        TrieNode* next[CHARNUMS];
        TrieNode(int _index):index(_index){
            for(int i = 0;i < CHARNUMS; i ++){
                next[i] = nullptr;
            }
        }
    };

    TrieNode* root;
    int triecnt;

    int gettrieindex(TrieNode* node,string& key,int index){
        if(key[index] == '\0' ){
            if(node->index == 0){
                node->index = triecnt++;
            }
            return node->index;
        }
        
        if(node->next[key[index]] == nullptr){
            node->next[key[index]] = new TrieNode(0);
        }

        return  gettrieindex(node->next[key[index]],key,index+1);
    }
public:
    struct  Edge
    {
        int e;
        int t;
        int next;

        Edge():e(0),t(0),next(-1){}
    };
    
    Solution(){
        triecnt = 0;
        root = new TrieNode(triecnt++);
    }

    int getindex(string& key){
        return gettrieindex(root,key,0);
    }

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

//         string start,end;
//         start.resize(MAXLENGTH);
//         end.resize(MAXLENGTH);
//         scanf("%s%s",&start[0],&end[0]);
//         int startid = solution.getindex(start);
//         int endid = solution.getindex(end);

//         vector<int> vertice(VERTICEMAX,-1);
//         vector<Solution::Edge> edges(n);
//         string s,e;
//         int t;
//         s.resize(MAXLENGTH);
//         e.resize(MAXLENGTH);
//         int sid;
//         int eid;
//         for(int i = 0; i < n; i ++){            
//             scanf("%s%s%d",&s[0],&e[0],&t);
//             sid = solution.getindex(s);
//             eid = solution.getindex(e);

//             edges[i].e = eid;
//             edges[i].t = t;
//             edges[i].next = vertice[sid];
//             vertice[sid] = i;

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