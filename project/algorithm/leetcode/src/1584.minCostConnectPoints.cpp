#include"leetcode.h"

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> mindistance(n,INT_MAX);
        vector<char> visit(n,0);
        int ret = 0;
        int counter = 0;
        auto cmp = [](pair<int,int> &a,pair<int,int> &b){
            if(a.second == b.second){
                return a.first>b.first;
            }
            return a.second > b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
        pq.push({0,0});
        pair<int,int> top;
        int distance;
        while (counter<n)
        {
            top = pq.top();
            pq.pop();
            if(visit[top.first] == 0){
                ret += top.second;
                counter++;
                visit[top.first] = 1;
                for(int i = 0; i < n; i ++){
                    if(visit[i]==0){
                        distance = abs(points[i][0] - points[top.first][0]) + abs(points[i][1] - points[top.first][1]);
                        if(distance < mindistance[i]){
                            mindistance[i] = distance;
                            pq.push({i,distance});
                        }
                    }
                }
            }
        }
        return ret;
        
    }
};