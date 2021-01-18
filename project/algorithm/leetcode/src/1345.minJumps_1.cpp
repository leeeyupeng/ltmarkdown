#include"leetcode.h"

class Solution {
    struct ListNode{
        int next;
        ListNode():next(-1){}
    };
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        vector<ListNode> list = vector<ListNode>(n);
        unordered_map<int,int> um;
        for(int i = 0; i < n; i ++){
            if(um.find(arr[i])==um.end()){
                um.insert({arr[i],i});
            }
            else{
                list[i].next = um[arr[i]];
                um[arr[i]] = i;
            }
        }
        int target = n-1;
        auto cmp=[](pair<int,pair<int,int>>&a,pair<int,pair<int,int>>&b){
            if(a.second.second ==  b.second.second){
                return a.first > b.first;
            }
            return a.second.second > b.second.second;
        };
        queue<pair<int,int>> q;

        q.push({0,0});

        vector<char> visit(n,0);
        visit[0] = 1;
        pair<int,int> cur;
        int next;
        while(!q.empty()){
            cur = q.front();
            q.pop();
            if(cur.first == target){return cur.second;}

            next = cur.first - 1;
            if(next>=0 && visit[next] == 0){
                q.push({next,cur.second+1});
                visit[next] = 1;
            }

            next = cur.first + 1;
            if(next<n&&visit[next]==0){
                q.push({next,cur.second+1});
                visit[next] = 1;
            }

            if(um.find(arr[cur.first])!=um.end()){
                next = um[arr[cur.first]];
                while(next!=-1){
                    if(visit[next]==0){
                        q.push({next,cur.second+1});
                        visit[next] = 1;
                    }
                    next = list[next].next;
                }
                um.erase(arr[cur.first]);
            }
        }
        return -1;
    }
};

// int main(){
//     int n;
//     while(scanf("%d",&n)){
//         vector<int> arr(n);
//         for(int i = 0; i < n; i ++){
//             arr[i] = rand() % 100000000;
//         }
//         Solution solution;
//         int ret  = solution.minJumps(arr);
//         cout<<"ret:"<<ret<<endl;
//     }
//     return 0;
// }