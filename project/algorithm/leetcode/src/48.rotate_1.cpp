#include"leetcode.h"
class Solution {
    struct Grid{
        int x;
        int y;
        Grid():x(0),y(0){}
        Grid(int _x,int _y):x(_x),y(_y){}
        Grid(Grid& grid):x(grid.x),y(grid.y){}
    };
private:
    int n;
    inline Grid getnext(Grid& pos){
        return {pos.y,n-1-pos.x};
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        n = matrix.size();
        int curvalue;
        int temp;
        Grid curpos;
        Grid nextpos;
        for(int i = 0; i < (n>>1);i ++){
            for(int j = i;j < n-1-i;j ++){
                curpos = {i,j};
                curvalue=matrix[curpos.x][curpos.y];
                do{                    
                    nextpos=getnext(curpos);
                    temp = matrix[nextpos.x][nextpos.y];
                    matrix[nextpos.x][nextpos.y] = curvalue;
                    curvalue = temp;   
                    curpos = nextpos;
                } while(!(curpos.x == i&&curpos.y == j));         
            }
        }
    }
};

// int main(){
//     Solution solution;
//     vector<vector<int>>  matrix={
//   {1,2,3,4,5,6},
//   {7,8,9,10,11,12},
//   {13,14,15,16,17,18},
//   {19,20,21,22,23,24},
//   {25,26,27,28,29,30},
//   {31,32,33,34,35,36}
//     };
//     solution.rotate(matrix);
//     return 0;
// }