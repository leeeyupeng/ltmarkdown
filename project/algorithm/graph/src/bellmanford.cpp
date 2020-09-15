#include"graph.h"

/*
 * 正边权 单源多目标最短路径
 * graph 邻接矩阵
 * start 源点
 * dist[i] start点到i点的最短路径数组
*/
void bellmanford_1(vector<vector<int>>& graph,int start,vector<int>& dist){
	queue<int> q;
    q.push(start);
    int i = 0;
    int v;
    while(!q.empty()){
        v = q.front();
        q.pop();
        for(i = 0; i < graph[v].size(); i ++){
            if(dist[i] > dist[v] + graph[v][i]){
                dist[i] = dist[v] + graph[v][i];
                q.push(i);
            }
        }
    }
}

/*
 * 单元多目标最短路径
 * 所有的边权值相同为1
 * graph 邻接链表
 * start 源点
 * dist[i] start点到i点的最短路径数组
 * 
 * 因为边权值相同都为1，就将问题转化为了树的层遍历
 * 
 * https://leetcode-cn.com/problems/Za25hA/ 追逐游戏
*/
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