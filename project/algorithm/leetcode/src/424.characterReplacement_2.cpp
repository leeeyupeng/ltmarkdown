#include"leetcode.h"

#define CHARNUM 26
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int ret = 0;
        char c;
        k = min(n,k);
        int cmax = 0;
        int cindex;
        vector<int> counter(CHARNUM,0);
        int i=0,j=0;
        while(j<n){
            if(j-i+1 - cmax <= k){
                ret = max(ret,j - i +1);
                j++;
                if(j>=n){break;}
                counter[s[j]-'A']++;
                cmax=0;
                for(int cn = 0;cn<CHARNUM;cn++){cmax=max(cmax,counter[cn]);}                
            }
            else{
                i++;
                counter[s[i]-'A']--;
                cmax=0;
                for(int cn = 0;cn<CHARNUM;cn++){cmax=max(cmax,counter[cn]);}
            }
        }
        return ret;
    }
};