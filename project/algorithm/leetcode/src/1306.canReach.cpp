#include"leetcode.h"

class Solution {
private:
    int n;
    unordered_set<int> us;
    bool dfs(vector<int>& arr,int index){
        if(index<0){return false;}
        if(index>=n){return false;}
        if(us.find(index)!=us.end()){
            return false;
        }
        if(arr[index] == 0){return true;}
        us.insert(index);
        return dfs(arr,index-arr[index]) || dfs(arr,index+arr[index]);
    }
public:
    bool canReach(vector<int>& arr, int start) {
        this->n = arr.size();
        return dfs(arr,start);
    }
};