#include"leetcode.h"

class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        int rnums = 0;
        int dnums = 0;
        vector<char> vflag(n,0);
        for(int i = 0; i < n; i ++){
            if(senate[i] == 'R'){
                rnums++;
            }
            else{
                dnums++;
            }
        }
        if(dnums==0){
            return "Radiant";
        }
        if(rnums==0){
            return "Dire";
        }
        int i=0,j=0;
        while(true){
            if(vflag[i] == 0){
                if(senate[i] == 'R'){
                    dnums--;
                    if(dnums==0){
                        return "Radiant";
                    }
                    j = i + 1;
                    if(j==n){j-=n;}
                    while(true){
                        if(senate[j] == 'D' && vflag[j] == 0){
                            vflag[j] = 1;
                            break;
                        }
                        j++;
                        if(j==n){j-=n;}
                    }
                }
                else{
                    rnums--;
                    if(rnums==0){
                        return "Dire";
                    }
                    j = i + 1;
                    if(j==n){j-=n;}
                    while(true){
                        if(senate[j] == 'R' && vflag[j] == 0){
                            vflag[j] = 1;
                            break;
                        }
                        j++;
                        if(j==n){j-=n;}
                    }
                }
            }

            i++;
            if(i == n){i-=n;}
        }
        return "";
    }
};

// int main(){
//     Solution solution;
//     string ans = solution.predictPartyVictory("RRDDD");

//     return 0;
// }