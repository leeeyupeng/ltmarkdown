#include"leetcode.h"

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        pair<int,int> step[2] = {{a,1},{a-b,2}};
        int maxx = max(x,x+2*b+a+a+300);
        vector<char> vf(maxx+1,1);
        int fn = forbidden.size();
        for(int i = 0; i < fn; i ++){
            if(forbidden[i] <= maxx){
                vf[forbidden[i]] = 0;
            }
        }
        auto cmp=[](pair<int,int>&a,pair<int,int>&b){
            if(a.second == b.second){
                return a.first > b.first;
            }
            return a.second > b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> q(cmp);
        q.push({0,0});
        vector<char> visit(maxx+1,0);
        pair<int,int> cur;
        while(!q.empty()){
            cur = q.top();
            q.pop();
            if(cur.first == x){
                return cur.second;
            }
            if(visit[cur.first] == 1){
                continue;
            }
            visit[cur.first] = 1;
            if(cur.first + step[0].first <= maxx && vf[cur.first + step[0].first]==1&& visit[cur.first + step[0].first] == 0) {
                q.push({cur.first + step[0].first,cur.second + step[0].second});
            }

            if(cur.first + step[1].first >=0 && cur.first + step[1].first <= maxx && vf[cur.first + step[1].first]==1 && cur.first + a <= maxx&& vf[cur.first+ a]==1 && visit[cur.first + step[1].first] == 0){
                q.push({cur.first + step[1].first,cur.second + step[1].second});
            }
        }
        return -1;
    }
};

// int main(){
//     vector<int> forbidden={
// 162,118,178,152,167,100,40,74,199,186,26,73,200,127,30,124,193,84,184,36,103,149,153,9,54,154,133,95,45,198,79,157,64,122,59,71,48,177,82,35,14,176,16,108,111,6,168,31,134,164,136,72,98
//     };

//     Solution solution;
//     int ret = solution.minimumJumps(forbidden,29,98,80);

//     return 0;
// }