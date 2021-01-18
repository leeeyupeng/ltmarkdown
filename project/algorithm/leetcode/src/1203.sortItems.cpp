#include"leetcode.h"

class Solution {
private:
    struct Edge{
        int t;
        int next;
        Edge(int _t):t(_t){}
    };
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<int> degrees(n,0);
        vector<int> vertices(n,-1);
        vector<Edge> edges;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < beforeItems[i].size(); j ++){
                edges.push_back(Edge(i));
                edges.back().next = vertices[beforeItems[i][j]];
                vertices[beforeItems[i][j]] = edges.size()-1;
                degrees[i] ++;
            }
        }
        auto cmp = [&group](int a,int b){
            if(group[a] == group[b]){
                return a<b;
            }
            return group[a] < group[b];
        };
        priority_queue<int,vector<int>,decltype(cmp)> q(cmp);
        for(int i = 0; i < n; i ++){
            if(degrees[i] == 0){
                q.push(i);
            }
        }

        int cnt = 0;
        int front;
        vector<int> beforeindex(n,0);
        vector<vector<int>> gg(m);
        int edgeid;
        int indexgg;
        while(!q.empty()){
            front = q.top();
            q.pop();
            cnt++;

            if(group[front] == -1){
                indexgg = beforeindex[front];
                gg[indexgg].push_back(front);
            }
            else if(group[front] >= beforeindex[front]){
                indexgg = group[front];
                gg[indexgg].push_back(front);
            }
            else{
                return vector<int>();
            }
            edgeid = vertices[front];
            while(edgeid!=-1){
                degrees[edges[edgeid].t] --;
                if(degrees[edges[edgeid].t] == 0){
                    q.push(edges[edgeid].t);
                }
                beforeindex[edges[edgeid].t] = indexgg;
                edgeid = edges[edgeid].next;
            }
        }

        vector<int> ans;
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < gg[i].size();j ++){
                ans.push_back(gg[i][j]);
            }
        }

        if(ans.size() != n){
            return vector<int>();
        }
        return ans;
    }
};