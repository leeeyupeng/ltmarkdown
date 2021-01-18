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
        vector<int> mdegrees(m,0);
        vector<int> vertices(n,-1);
        vector<Edge> edges;

        for(int i = 0; i < n; i ++){
            for(int j = 0; j < beforeItems[i].size(); j ++){
                edges.push_back(Edge(i));
                edges.back().next = vertices[beforeItems[i][j]];
                vertices[beforeItems[i][j]] = edges.size()-1;
                degrees[i] ++;
                if(group[i]!=-1 && group[i]!= group[beforeItems[i][j]]){
                    mdegrees[group[i]] ++;
                }
            }
        }
        int curgroup=-1;
        auto cmp = [&group,&curgroup](int a,int b){
            if(group[a] == -1 && group[b] == -1){
                return a>b;
            }
            else if(group[a] == -1){
                return true;
            }
            else if(group[b] == -1){
                return false;
            }
            else if(group[a] == curgroup && group[b] == curgroup){
                return a>b;
            }
            else if(group[a] == curgroup){
                return false;
            }
            else if(group[b] == curgroup){
                return true;
            }
            else if(group[a] == group[b]){
                return a>b;
            }
            return group[a] > group[b];
        };
        priority_queue<int,vector<int>,decltype(cmp)> q(cmp);
        vector<vector<int>> degreezero(m);
        for(int i = 0; i < n; i ++){
            if(degrees[i] == 0){
                if(group[i] == -1 || mdegrees[group[i]] == 0){
                    q.push(i);
                }
                else
                {
                    degreezero[group[i]].push_back(i);
                }
            }
        }

        int cnt = 0;
        int top;
        vector<int> ans;
        int edgeid;
        int t;
        int groupid;
        while(!q.empty()){
            top = q.top();
            q.pop();
            curgroup = group[top];
            cnt++;
            ans.push_back(top);
            
            edgeid = vertices[top];
            while(edgeid!=-1){
                t = edges[edgeid].t;
                degrees[t] --;
                groupid = group[t];
                if(degrees[t] == 0){
                    if(groupid== -1 || mdegrees[groupid] == 0){
                        q.push(t);
                    }                    
                    else{
                        degreezero[groupid].push_back(t);
                    }
                }
                if(groupid!=-1 && group[top]!=groupid)
                {
                    mdegrees[groupid] --;
                    if(mdegrees[groupid]==0){
                        while(!degreezero[groupid].empty()){
                            q.push(degreezero[groupid].back());
                            degreezero[groupid].pop_back();
                        }
                    }
                }
                edgeid = edges[edgeid].next;
            }
        }

        if(cnt != n){
            return vector<int>();
        }
        return ans;
    }
};

// int main(){
//     int n = 8;
//     int m = 2;
//     vector<int> group={
// -1,-1,1,0,0,1,0,-1
//     };
//     vector<vector<int>> beforeItems={
// {},{6},{5},{6},{3,6},{},{},{}
//     };
//     Solution solution;
//     auto ret = solution.sortItems(n,m,group,beforeItems);
//     return 0;
// }