#include"leetcode.h"

class Solution {
public:
    int minJump(vector<int>& jump) {
        int n = jump.size();
        auto cmp = [](pair<int,int> a,pair<int,int> b){if(a.second == b.second){return a.first>b.first;}return a.second>b.second;};
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> q(cmp);
        int temp;
        int step;
        int ans = INT_MAX;
        pair<int,int> qmin;
        if(jump[0]>=n){return 1;}
        else{q.push({jump[0],1});}
        for(int i = 0; i < n;i ++){
            while(!q.empty() && q.top().first<i){q.pop();}
            if(q.empty()){break;}
            qmin = q.top();
            if(qmin.first == i){step = qmin.second;}
            else if(qmin.first>i){step = qmin.second + 1;}
            temp = i+jump[i];
            if(temp<n){
                if(qmin.first<temp){
                    q.push({temp,step+1});
                }
            }
            else{ans = min(ans,step+1);}
        }
        return ans;
    }
};

// int main(){
//     vector<int> jump={
//         4,3,2,8,3,5,3,5,7,8,6,10,3,7,3,10,7,10,10,9,1,4,7,4,8,6,9,8,8,2,7,2,4,5,4,3,3,2,2,2,3,4,4,1,1,5,6,8,1,2
//     };
//     Solution solution;
//     int ans = solution.minJump(jump);
//     return 0;
// }