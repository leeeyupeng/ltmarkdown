#include"leetcode.h"

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        q.push(start);
        int index;
        vector<char> visit(n,0);
        visit[start] = 1;
        int temp;
        while(!q.empty()){
            index = q.front();
            q.pop();
            if(arr[index] == 0){return true;}
            temp = index-arr[index];
            if(temp>=0 && visit[temp]==0){
                q.push(temp);
                visit[temp] = 1;
            }
            temp = index+arr[index];
            if(temp < n && visit[temp] == 0){
                q.push(temp);
                visit[temp] = 1;
            }
        }
        return false;
    }
};