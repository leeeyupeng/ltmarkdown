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
        for(int i = 0; i < n;i ++){
            //if(i>0 && s[i] == s[i-1]){continue;}
            if(n-i<ret){break;}
            for(int cn = 0; cn < CHARNUM; cn++){counter[cn] = 0;}
            cmax = 0;
            for(int j = i;j < n;j++){
                cindex = s[j]-'A';
                counter[cindex] ++;
                if(counter[cindex]>cmax){
                    cmax = counter[cindex];                    
                }
                if(j-i +1 - cmax > k){
                    break;
                }
                else{
                    ret = max(ret,j - i +1);
                }
            }
        }
        return ret;
    }
};