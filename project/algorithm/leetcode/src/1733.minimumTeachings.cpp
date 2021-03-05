#include"leetcode.h"

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int pn = languages.size();
        vector<vector<char>> vvl(n+1,vector<char>(pn+1,0));
        for(int i = 0; i < pn; i ++){
            for(int j = 0; j < languages[i].size(); j ++){
                vvl[languages[i][j]][i+1] = 1;
            }
        }
        int fn = friendships.size();
        vector<char> fsok(fn,0);
        for(int i = 0; i < fn; i ++){
            for(int j = 1; j <= n; j ++){
                if(vvl[j][friendships[i][0]] == 1 && vvl[j][friendships[i][1]] == 1){
                    fsok[i] = 1;
                    break;
                }
            }
        }

        int ret = INT_MAX;
        int counter;
       
        for(int i = 1; i  <= n; i ++){
            counter = 0;
            for(int j = 0;j < fn; j ++){
                if(fsok[j] == 0){
                    if(vvl[i][friendships[j][0]] == 0){counter++;vvl[i][friendships[j][0]] = 1;}
                    if(vvl[i][friendships[j][1]] == 0){counter++;vvl[i][friendships[j][1]] = 1;}
                }
            }
            ret = min(ret,counter);
        }
        return ret;
    }
};