#include"leetcode.h"
class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        pair<int,int> step[2] = {{a,1},{a-b,2}};

        unordered_set<int> usf;
        int fn = forbidden.size();
        int maxf = 0;
        for(int i = 0; i < fn; i ++){
            usf.insert(forbidden[i]);
            maxf=max(maxf,forbidden[i]);
        }
        int maxx = max(x+((b)<<1),maxf+((b)<<1));
        auto cmp=[](pair<int,int>&a,pair<int,int>&b){
            if(a.second == b.second){
                return a.first > b.first;
            }
            return a.second > b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> q(cmp);
        q.push({0,0});
        unordered_set<int> us;
        pair<int,int> cur;
        while(!q.empty()){
            cur = q.top();
            q.pop();
            if(cur.first == x){
                return cur.second;
            }
            if(us.find(cur.first) != us.end()){
                continue;
            }
            us.insert(cur.first);
            if(cur.first + step[0].first < maxx && usf.find(cur.first + step[0].first)==usf.end() && us.find(cur.first + step[0].first)==us.end()) {
                q.push({cur.first + step[0].first,cur.second + step[0].second});
            }

            if(cur.first + step[1].first >=0 && cur.first + a < maxx && usf.find(cur.first + step[1].first)==usf.end() && us.find(cur.first + step[1].first)==us.end()
            &&usf.find(cur.first + a)==usf.end()){
                q.push({cur.first + step[1].first,cur.second + step[1].second});
            }
        }
        return -1;
    }
};