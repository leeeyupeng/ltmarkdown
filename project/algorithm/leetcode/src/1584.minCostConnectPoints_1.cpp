#include"leetcode.h"

class Solution {
private:
    struct Edge{
        int s;
        int t;
        int c;
        Edge(int _s,int _t,int _c):s(_s),t(_t),c(_c){}
    };
    int find(vector<int> &us,int index){
        if(us[index]!=index){
            us[index] = find(us,us[index]);
        }
        return us[index];
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        auto cmp=[](Edge &a,Edge &b){
            if(a.c == b.c){
                if(a.s == b.s){
                    return a.t > b.t;
                }
                return a.s > b.s;
            }
            return a.c > b.c;
        };
        priority_queue<Edge,vector<Edge>,decltype(cmp)> pq(cmp); 
        for(int i = 0; i < n; i ++){
            for(int j = i + 1; j < n ; j++){
                pq.push({i,j,abs(points[j][0]- points[i][0]) + abs(points[j][1] - points[i][1])});
            }
        }
        vector<int> us(n,0);
        for(int i = 0; i < n; i++){us[i] = i;}
        Edge top(0,0,0);
        int a,b;
        int ret = 0;
        int counter = 0;
        while(!pq.empty() && counter < n-1){
            top = pq.top();
            pq.pop();
            a = find(us,top.s);
            b  = find(us,top.t);
            if(a!=b){
                ret += top.c;
                us[b] = a;
                counter ++;
            }
        }
        return ret;
    }
};