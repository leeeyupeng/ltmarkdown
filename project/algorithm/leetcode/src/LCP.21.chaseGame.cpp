#include"leetcode.h"

class Solution {
private:
    void bellmanford_2(vector<vector<int>>& graph,int start,vector<int>& dist){
        int n = graph.size();
        vector<bool> visit(n);
        for(int i = 0; i < n; i ++){visit[i] = false;}
        queue<int> q;
        q.push(start);
        visit[start] = true;
        dist[start] = 0;
        int i = 0;
        int v;    
        while(!q.empty()){
            v = q.front();
            q.pop();
            for(i = 0; i < graph[v].size(); i ++){
                if(visit[graph[v][i]] == false){
                    dist[graph[v][i]] = dist[v] + 1;
                    q.push(graph[v][i]);
                    visit[graph[v][i]] = true;
                }
            }
        }
    }

    void cycle_2(vector<vector<int>>& graph,vector<bool>& vincycle){
        int n  = graph.size();
        vector<int> degree(n);
        queue<int> q;
        for(int i = 0; i < n; i ++){
            degree[i] = graph[i].size();
            if(degree[i] == 1){q.push(i);}
        }
        for(int i = 0; i < n; i ++){vincycle[i] = true;}
        int v;
        while(!q.empty()){
            v = q.front();
            q.pop();
            vincycle[v] = false;
            for(int i = 0; i < graph[v].size();i++){
                degree[graph[v][i]] --;
                if(degree[graph[v][i]] == 1){q.push(graph[v][i]);}
            }
        }
    }
public:
    int chaseGame(vector<vector<int>>& edges, int startA, int startB) {
        if(startA == startB){return 0;}
        int n = edges.size();
        vector<vector<int>> graph(n,vector<int>());
        for(int i = 0; i < n; i ++){
            graph[edges[i][0]-1].push_back(edges[i][1]-1);
            graph[edges[i][1]-1].push_back(edges[i][0]-1);
        }

        vector<int> dista=vector<int>(n);
        bellmanford_2(graph,startA-1,dista);
        vector<int> distb=vector<int>(n);
        bellmanford_2(graph,startB-1,distb);

        vector<bool> vincycle(n);
        //cycle_1(graph,vincycle);
        cycle_2(graph,vincycle);
        int cyclecount = 0;
        for(int i = 0; i < n; i ++){cyclecount +=vincycle[i]==true?1:0;}
        int ans = 1;
        for(int i = 0; i <n; i ++){
            if(dista[i] > distb[i] + 1){
                if(cyclecount > 3 && vincycle[i] == true){ans = -1;break;}
                ans = max(ans,dista[i]);
            }
        }
        return ans;
    }
};

// int main(){
//     Solution s;
//     vector<vector<int>> edges={
// {1,2},{2,3},{3,1},{3,6},{2,4},{4,5},{5,8},{4,7},{8,9}
//     };
//     int startA=9;
//     int startB=7;
//     int ans = s.chaseGame(edges,startA,startB);
//     cout<<"ans:"<<ans<<endl;
//     return 0;
// }