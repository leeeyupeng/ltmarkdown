#include"leetcode.h"

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if(n<=2){return true;}
        int x1 = coordinates[1][0] - coordinates[0][0];
        int y1 = coordinates[1][1] - coordinates[0][1];
        for(int i = 2;i < n; i ++){
            if(x1 * (coordinates[i][1] - coordinates[0][1]) != (coordinates[i][0] - coordinates[0][0]) * y1){
                return false;
            }
        }
        return true;
    }
};