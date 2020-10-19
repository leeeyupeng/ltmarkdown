#include"leetcode.h"

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<char>> pp(n,vector<char>(n));
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j++){
                pp[i][j] = 0;
            }
        }

        vector<int> p(n);
        for(int i = 0; i < n; i ++){
            p[i]=0;
        }
        int roadnums = roads.size();
        for(int i = 0; i < roadnums; i ++){
            pp[roads[i][0]][roads[i][1]] ++;

            p[roads[i][0]]++;
            p[roads[i][1]]++;
        }

        int ans = 0;
        for(int i = 0; i < n; i ++){
            for(int j = i+1; j < n; j ++){
                ans = max(ans,p[i]+p[j] - (pp[i][j]+pp[j][i]));
            }
        }
        return ans;
    }
};