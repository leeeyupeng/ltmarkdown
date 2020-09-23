#include"leetcode.h"

class Solution {
public:
    vector<int> numsGame(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,long long>* map = new unordered_map<int,long long>();
        unordered_map<int,long long>* mapnext = new unordered_map<int,long long>();
        vector<int> ans(n);
        map->insert({nums[0],0});
        ans[0] = 0;
        int index = 1;
        long long minstep=LONG_LONG_MAX;
        while(index<n){
            minstep=LONG_LONG_MAX;
            (*mapnext)[nums[index]] = LONG_LONG_MAX;
            for(unordered_map<int,long long>::iterator ite = map->begin();ite!=map->end();ite++){                
                if(mapnext->find(ite->first+1)!=mapnext->end()){
                    (*mapnext)[ite->first+1]=min((*mapnext)[ite->first+1],ite->second+abs(nums[index] - (ite->first+1)));
                }
                else{
                    (*mapnext)[ite->first+1]=ite->second+abs(nums[index] - (ite->first+1));
                }
                minstep = min(minstep,(*mapnext)[ite->first+1]);
                
                (*mapnext)[nums[index]]=min((*mapnext)[nums[index]],ite->second+index * abs(nums[index] - 1  - ite->first));
                
            }
            minstep = min(minstep,(*mapnext)[nums[index]]);
            ans[index] = minstep%1000000007;
            index++;
            map->clear();
            swap(map,mapnext);
        }
        return ans;
    }
};

// int main(){
//     vector<int> nums;
//     for(int i = 0; i < 10000; i ++){
//         nums.push_back(rand()%1000);
//     }
//     Solution solution;
//     vector<int> ans = solution.numsGame(nums);
//     return 0;
// }