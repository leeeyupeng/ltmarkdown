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
            if(group[i] == -1){group[i]=m;}
        }
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < beforeItems[i].size(); j ++){
                edges.push_back(Edge(i));
                edges.back().next = vertices[beforeItems[i][j]];
                vertices[beforeItems[i][j]] = edges.size()-1;
                degrees[i] ++;
                if(group[i]!=m && group[i]!= group[beforeItems[i][j]]){
                    mdegrees[group[i]] ++;
                }
            }
        }
        queue<int> mq;
        vector<vector<int>> degreezero(m+1);
        for(int i = 0; i < m; i ++){
            if(mdegrees[i] == 0){
                mq.push(i);
            }
        }
        for(int i = 0; i < n; i ++){
            if(degrees[i] == 0){
                degreezero[group[i]].push_back(i);
            }
        }

        int cnt = 0;
        int mtop;
        int top;
        vector<int> ans;
        int edgeid;
        int t;
        int groupid;
        
        while(!mq.empty() || !degreezero[m].empty()){
            if(!mq.empty()){
                mtop = mq.front();
                mq.pop();
            }
            else{
                mtop = m;
            }
            while(!degreezero[mtop].empty()){
                top = degreezero[mtop].back();
                degreezero[mtop].pop_back();
                cnt++;
                ans.push_back(top);
                
                edgeid = vertices[top];
                while(edgeid!=-1){
                    t = edges[edgeid].t;
                    degrees[t] --;
                    groupid = group[t];
                    if(degrees[t] == 0){
                        degreezero[groupid].push_back(t);
                    }
                    if(groupid != m && group[top]!=groupid)
                    {
                        mdegrees[groupid] --;
                        if(mdegrees[groupid]==0){
                            mq.push(groupid);
                        }
                    }
                    edgeid = edges[edgeid].next;
                }
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