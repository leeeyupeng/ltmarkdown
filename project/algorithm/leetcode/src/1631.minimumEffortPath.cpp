#include"leetcode.h"


class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rown = heights.size();
        int coln = heights[0].size();
        pair<int,int> start = {0,0};
        pair<int,int> target = {rown-1,coln -1};

        auto cmp = [](pair<pair<int,int>,pair<int,int>> &a,pair<pair<int,int>,pair<int,int>> &b){
            if(max(a.second.first,a.second.second) == max(b.second.first , b.second.second)){
                return a.second.first > b.second.first;
            }
            return max(a.second.first,a.second.second) > max(b.second.first , b.second.second);
        };
        priority_queue<pair<pair<int,int>,pair<int,int>>,vector<pair<pair<int,int>,pair<int,int>>>,decltype(cmp)> pq(cmp);
        pq.push({{0,0},{0,0}});//abs(heights[target.first][target.second] - heights[start.first][start.second])}});
        vector<vector<char>> visit(rown,vector<char>(coln,0));
        pair<pair<int,int>,pair<int,int>>  top;
        vector<pair<int,int>> offset= {{-1,0},{1,0},{0,-1},{0,1}};
        int offsetn = offset.size();
        pair<int,int> temp;
        int temph;
        int tempg;
        while(!pq.empty()){
            top  = pq.top();
            pq.pop();
            if(visit[top.first.first][top.first.second] == 1){continue;}
            visit[top.first.first][top.first.second] = 1;
            if(top.first == target){return top.second.first;}
            
            for(int i = 0; i < offsetn; i ++){
                temp = {top.first.first + offset[i].first,top.first.second+offset[i].second};
                if(temp.first >= 0 && temp.first < rown && temp.second >= 0 && temp.second < coln){
                    if(visit[temp.first][temp.second] == 0){
                        temph = max(top.second.first,abs(heights[temp.first][temp.second] - heights[top.first.first][top.first.second]));
                        tempg = 0;//abs(heights[target.first][target.second] - heights[temp.first][temp.second]);
                        pq.push({temp,{temph,tempg}});
                    }
                }
            }
        }
        return -1;
    }
};