#include"leetcode.h"

class Solution {
private:
    int find(vector<int> &us,int index){
        if(us[index]!=index){
            us[index] = find(us,us[index]);
        }
        return us[index];
    }
    void uni(vector<int> &us,int a,int b){
        a = find(us,a);
        b = find(us,b);
        if(a!=b){
            us[b] = a;
        }
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int nn = n*n;
        vector<int> us(nn<<2,0);
        for(int i = 0; i < nn<<2; i ++){us[i] = i;}
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++){
                if(grid[i][j] == '\\'){
                    uni(us,((n*i+j)<<2) + 0,((n*i+j)<<2) + 2);
                    uni(us,((n*i+j)<<2) + 1,((n*i+j)<<2) + 3);
                }
                else if(grid[i][j] == '/'){
                    uni(us,((n*i+j)<<2) + 0,((n*i+j)<<2) + 1);
                    uni(us,((n*i+j)<<2) + 2,((n*i+j)<<2) + 3);
                }
                else{
                    uni(us,((n*i+j)<<2) + 0,((n*i+j)<<2) + 1);
                    uni(us,((n*i+j)<<2) + 0,((n*i+j)<<2) + 2);
                    uni(us,((n*i+j)<<2) + 0,((n*i+j)<<2) + 3);
                }
                if(i>0){
                    uni(us,((n*i+j)<<2) + 0,((n*(i-1)+j)<<2) + 3);
                }
                if(j>0){
                    uni(us,((n*i+j)<<2) + 1,((n*i+j-1)<<2) + 2);
                }
            }
        }
        int ret = 0;
        for(int i = 0; i < nn<<2; i ++){if(us[i] == i){ret ++;}}
        return ret;
    }
};

// int main(){
//     vector<string> grid={
//          " /",
//   "/ ",
//     };

//     Solution solution;
//     int ret = solution.regionsBySlashes(grid);

//     return 0;
// }