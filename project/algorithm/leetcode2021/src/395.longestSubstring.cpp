#include"leetcode.h"


#define CHARNUM 26
class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        int ret = 0;
        vector<int> nums(CHARNUM,0);
        bool flag=false;
        for(int i = 0; i < n; i ++){
            nums[s[i]-'a'] ++;
        }
        vector<int> nums2(CHARNUM,0);
        for(int i = 0; i < n; i ++){
            if(n-i<=ret){break;}
            for(int c = 0; c< CHARNUM; c++){nums2[c] = nums[c];}
            flag = true;
            for(int c = 0; c < CHARNUM; c ++){
                if(nums2[c]!= 0 && nums2[c] < k){flag = false;break;}
            }
            if(flag == true){
                ret = max(ret,n-i);
            }
            else{
                for(int j = n - 1; j > ret + i - 1;j --){
                    nums2[s[j]-'a'] --;
                    if(nums2[s[j]-'a'] == 0){
                        flag = true;
                        for(int c = 0; c < CHARNUM; c ++){
                            if(nums2[c]!= 0 && nums2[c] < k){flag = false;break;}
                        }
                        if(flag == true){
                            ret = max(ret,j-i);
                            break;
                        }
                    }
                }
            }

            nums[s[i]-'a']--;
        }
        return ret;
    }
};