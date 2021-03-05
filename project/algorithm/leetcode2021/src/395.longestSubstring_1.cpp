#include"leetcode.h"


#define CHARNUM 26
class Solution {
private:
    int _longestSubstring(string &s,int k,int start,int target){
        int ret = 0;
        vector<int> nums(CHARNUM,0);
        for(int i = start; i <= target; i ++){
            nums[s[i]-'a'] ++;
        }
        bool flag=true;
        for(int c = 0; c < CHARNUM; c ++){
            if(nums[c]!= 0 && nums[c] < k){flag = false;break;}
        }

        if(flag == true){
            return target - start + 1;
        }

        int i = start-1, j = start;
        while(j <= target){
            if(nums[s[j] - 'a'] < k){
                if(j-1>=0 && j-1 - (i + 1) > ret){
                    ret = max(ret,_longestSubstring(s,k,i+1,j-1));
                }
                i = j;
            }
            j ++;
        }
        if(i!=j-1){
            if(j-1>=0 && j-1 - (i + 1) > ret){
                ret = max(ret,_longestSubstring(s,k,i+1,j-1));
            }
        }

        return ret;
    }
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        return _longestSubstring(s,k,0,n-1);
    }
};

// int main(){
//     Solution solution;
//     string s = "abb";
//     int k = 2;
//     auto ret = solution.longestSubstring(s,k);
//     return 0;
// }