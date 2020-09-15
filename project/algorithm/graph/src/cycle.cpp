#include"graph.h"
/*
 * 单元多目标最短路径
 * 所有的边权值相同为1
 * graph 邻接链表
 * vincycle 顶点i是否在环上 
 *  
 * https://leetcode-cn.com/problems/Za25hA/ 追逐游戏
*/
void dfs(vector<vector<int>>& graph,int lastv,int v,vector<bool>& visit,vector<int>& path,vector<bool>& vincycle){
    if(visit[v] == true){
        for(int i = path.size() -1; i >=0;i --){
            vincycle[path[i]] = true;
            if(v == path[i]){break;}
        }
        return;
    }
    path.push_back(v);
    visit[v] = true;
    for(int i = 0;i<graph[v].size(); i ++){
        if(graph[v][i]!= lastv){
            dfs(graph,v,graph[v][i],visit,path,vincycle);
        }
    }
    visit[v] = false;
    path.pop_back();
}
void cycle_1(vector<vector<int>>& graph,vector<bool>& vincycle){
    int n = graph.size();
    vector<bool> visit(n);
    for(int i = 0; i < n; i ++){visit[i] = false;}
    for(int i = 0; i < n; i ++){vincycle[i] = false;}
    vector<int> path;
    dfs(graph,-1,1,visit,path,vincycle);
}

/*
 * 单元多目标最短路径
 * 所有的边权值相同为1
 * graph 邻接链表
 * vincycle 顶点i是否在环上 
 * 拓扑排序
 * https://leetcode-cn.com/problems/Za25hA/ 追逐游戏
*/
void cycle_2(vector<vector<int>>& graph,vector<bool>& vincycle,int cyclevnums){
    int n  = graph.size();
    vector<int> degree(n);
    queue<int> q;
    for(int i = 0; i < n; i ++){
        degree[i] = graph[i].size();
        if(degree[i] == 1){q.push(i);}
    }
    for(int i = 0; i < n; i ++){vincycle[i] = true;}
    int v;
    cyclevnums = n; 
    while(!q.empty()){
        v = q.front();
        q.pop();
        cyclevnums --;
        vincycle[v] = false;
        for(int i = 0; i < graph[v].size();i++){
            degree[graph[v][i]] --;
            if(degree[graph[v][i]] == 1){q.push(graph[v][i]);}
        }
    }
}