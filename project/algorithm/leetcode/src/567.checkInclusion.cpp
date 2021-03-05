#include"leetcode.h"

#define CHARUMS 26
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        int sums = n;
        vector<char> counter(CHARUMS,0);
        for(int i = 0; i < n; i ++){counter[s1[i]-'a']++;}
        int i = 0,j = 0;
        while(j<m){
            if(counter[s2[j]-'a']>0){
                counter[s2[j]-'a']--;j++;
                sums--;
                if(sums == 0){return true;}
            }
            else if(i==j){i++;j++;}
            else{
                counter[s2[i]-'a']++;i++;
                sums++;
            }
        }
        return false;
    }
};