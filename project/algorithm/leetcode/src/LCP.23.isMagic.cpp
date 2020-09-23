#include"leetcode.h"

class Solution {
private:
    int n;
    void swap(vector<int>& target,int start){
        queue<int> q0;
        queue<int> q1;
        int index = start;
        while(index<n){
            if((index-start)&0x1 == 0x1){
                q1.push(target[index]);
            }
            else{
                q0.push(target[index]);
            }
            index ++;
        }
        index = start;
        while(!q1.empty()){
            target[index++] = q1.front();
            q1.pop();
        }
        while(!q0.empty()){
            target[index++] = q0.front();
            q0.pop();
        }
    }
    bool dfs(vector<int>& target,vector<int>& orgin,int k,int index){
        swap(orgin,index);

        for(int i = 0; i < k && index+i<n; i ++){
            if(target[index+i]!=orgin[index+i]){return false;}
        }
        if(index+k>=n){return true;}
        return dfs(target,orgin,k,index+k);
    }
public:
    bool isMagic(vector<int>& target) {
        n = target.size();
        vector<int> orgin(n);
        for(int i = 0; i < n; i ++){orgin[i] = i+1;}
        swap(orgin,0);
        int k = 0;
        for(int i = 0; i < n; i ++){
            if(target[i] == orgin[i]){k=i+1;}
            else{break;}
        }
        if(k == 0){return false;}
        if(k == n){return true;}

        return dfs(target,orgin,k,k);
    }
};

// int main(){
//     vector<int> target={
// 1
//     };
//     Solution solution;
//     bool ans = solution.isMagic(target);
//     return ans;
// }