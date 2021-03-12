#include"leetcode.h"

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        if(n==0){return {};}
        vector<int> ret(n,-1);
        stack<int> sindex;
        int max = nums[0],maxindex = 0;
        for(int i = 0; i < n; i ++){
            while(!sindex.empty() && nums[i] > nums[sindex.top()]){
                ret[sindex.top()] = nums[i];
                sindex.pop();
            }
            sindex.push(i);
            if(nums[i] > max){max = nums[i];maxindex = i;}
        }
        if(maxindex!=n-1){
            for(int i = 0; i <= maxindex; i ++){
                while(!sindex.empty() && nums[i] > nums[sindex.top()]){
                    ret[sindex.top()] = nums[i];
                    sindex.pop();
                }
                if(ret[i] == -1){
                    sindex.push(i);
                }
            }
        }

        return ret;
    }
};