#include"leetcode.h"

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n==0){return 0;}
        
        vector<int> depth(n,1);
        for(int i = 0; i < n; i ++){
            depth[i]=1;
        }
        stack<int> s;
        s.push(0);
        int top;
        for(int i = 1; i < n; i ++){
            while(!s.empty() && ratings[s.top()] < ratings[i]){
                top = s.top();
                s.pop();
                if(top>0&&ratings[top-1]<ratings[top]){
                    depth[top] = max(depth[top],depth[top-1]+1);
                }
                if(top+1<n && ratings[top+1]<ratings[top]){
                    depth[top] = max(depth[top],depth[top+1]+1);
                }
            }
            s.push(i);
        }

        while(!s.empty()){
            top = s.top();
            s.pop();
            if(top>0&&ratings[top-1]<ratings[top]){
                depth[top] = max(depth[top],depth[top-1]+1);
            }
            if(top+1<n && ratings[top+1]<ratings[top]){
                depth[top] = max(depth[top],depth[top+1]+1);
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i ++){
            ans+=depth[i];
        }
        return ans;
    }
};