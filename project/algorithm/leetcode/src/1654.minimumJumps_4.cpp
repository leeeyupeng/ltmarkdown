#include"leetcode.h"
class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        pair<int,int> step[2] = {{a,1},{a-b,2}};

        
        int fn = forbidden.size();
        int maxf = 0;
        for(int i = 0; i < fn; i ++){
            maxf=max(maxf,forbidden[i]);
        }
        int maxx = max(x+((b)<<1),maxf+((b)<<1));
        vector<char> vf(maxx,1);
        for(int i = 0; i < fn; i ++){
            vf[forbidden[i]]=0;
        }
        auto cmp=[](pair<int,int>&a,pair<int,int>&b){
            if(a.second == b.second){
                return a.first > b.first;
            }
            return a.second > b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> q(cmp);
        q.push({0,0});
        vector<char> visit(maxx,0);
        pair<int,int> cur;
        while(!q.empty()){
            cur = q.top();
            q.pop();
            if(cur.first == x){
                return cur.second;
            }
            if(visit[cur.first]==1){
                continue;
            }
            visit[cur.first]=1;
            if(cur.first + step[0].first < maxx && vf[cur.first + step[0].first] == 1 && visit[cur.first + step[0].first]==0) {
                q.push({cur.first + step[0].first,cur.second + step[0].second});
            }

            if(cur.first + step[1].first >=0 && cur.first + a < maxx && vf[cur.first + step[1].first]==1&& visit[cur.first + step[1].first]==0
            &&vf[cur.first + a]==1){
                q.push({cur.first + step[1].first,cur.second + step[1].second});
            }
        }
        return -1;
    }
};