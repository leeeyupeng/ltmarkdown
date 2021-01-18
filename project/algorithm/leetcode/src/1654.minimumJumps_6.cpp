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
        vector<char> vf(maxx+1,1);
        for(int i = 0; i < fn; i ++){
            vf[forbidden[i]]=0;
        }
        auto cmp=[](pair<int,pair<int,int>>&a,pair<int,pair<int,int>>&b){
            if(a.second.first + a.second.second == b.second.first + b.second.second){
                return a.first > b.first;
            }
            return a.second.first + a.second.second > b.second.first + b.second.second;
        };
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,decltype(cmp)> q(cmp);
        q.push({x,{0,x/a + x%a==0?0:1}});
        vector<char> visit(maxx+1,0);
        pair<int,pair<int,int>> cur;
        int temp;
        while(!q.empty()){
            cur = q.top();
            q.pop();
            if(cur.first == 0){
                return cur.second.first;
            }
            if(visit[cur.first]==1){
                continue;
            }
            visit[cur.first]=1;
            temp = cur.first - step[0].first;
            if(temp >= 0 && vf[temp] == 1 && visit[temp]==0) {
                q.push({temp,{cur.second.first + step[0].second,temp/a + temp%a==0?0:1}});
            }

            temp = cur.first - step[1].first;
            if(temp >=0  && temp <=maxx && cur.first + b <= maxx && vf[temp]==1&& visit[temp]==0&&vf[cur.first + b]==1){
                q.push({cur.first - step[1].first,{cur.second.first + step[1].second,temp/a + temp%a==0?0:1}});
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