#include"leetcode.h"

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        priority_queue<int,vector<int>,greater<int>> pqmin;
        priority_queue<int,vector<int>,greater<int>> pqmin2;

        priority_queue<int,vector<int>,less<int>> pqmax;
        priority_queue<int,vector<int>,less<int>> pqmax2;

        int ret = 0;
        for(int i = 0;i < n;i++){
            if(pqmax.empty()){
                pqmin.push(nums[i]);
                pqmax.push(nums[i]);
            }
            else if(pqmax.top() - pqmin.top() > limit){
                pqmin2.push(nums[i]);
                pqmax2.push(nums[i]);
                while(!pqmin2.empty() && pqmin.top() == pqmin2.top()){
                    pqmin.pop();
                    pqmin2.pop();
                }
                while(!pqmax2.empty() && pqmax.top() == pqmax2.top()){
                    pqmax.pop();
                    pqmax2.pop();
                }
            }
            else{
                ret = max(ret,pqmax.top() - pqmin.top());
                pqmin.push(nums[i]);
                pqmax.push(nums[i]);
            }
            
        }
        return ret;
    }
};