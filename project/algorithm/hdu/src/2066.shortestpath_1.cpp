#include"hdu.h"

#define NMAX 1000
class Solution{
private:
    void floyd(vector<vector<int>>& matrix){
        for(int k = 1; k <= NMAX;k++){
            for(int i = 1; i <= NMAX; i ++){
                for(int j = 1; j <= NMAX;j ++){
                    if(matrix[i][k]!=-1&&matrix[k][j]!=-1){
                        if(matrix[i][j] == -1){
                            matrix[i][j] = matrix[i][k] + matrix[k][j];
                        }
                        else if(matrix[i][j] > matrix[i][k] + matrix[k][j]){
                            matrix[i][j] = matrix[i][k] + matrix[k][j];
                        }
                    }
                }
            }
        }
    }
public:
    int solve(int t,int s,int d,vector<vector<int>>& matrix,vector<int>& vs,vector<int>& vd){
        floyd(matrix);
        int ret= -1;
        for(int i = 0; i < s; i ++){
            for(int j = 0;j < d; j ++){
                if(vs[i] == vd[j]){return 0;}
                if(matrix[vs[i]][vd[j]] != -1){
                    if(ret == -1){
                        ret = matrix[vs[i]][vd[j]];
                    }
                    else if(ret > matrix[vs[i]][vd[j]]){
                        ret = matrix[vs[i]][vd[j]];
                    }
                }
            }
        }

        return ret;
    }
};
// int main(){
//     int t,s,d;
//     int a,b,time;
//     Solution solution;
//     while(scanf("%d%d%d",&t,&s,&d)!=EOF){
//         vector<vector<int>> matrix(NMAX+1,vector<int>(NMAX+1,-1));
//         for(int i = 0; i < t; i ++){
//             scanf("%d%d%d",&a,&b,&time);
//             if(matrix[a][b] == -1 || matrix[a][b] > time){
//                 matrix[a][b] = time;
//                 matrix[b][a] = time;
//             }
//         }

//         vector<int> vs(s);
//         for(int i = 0; i < s; i ++){
//             scanf("%d",&vs[i]);
//         }
//         vector<int> vd(d);
//         for(int i = 0; i < d; i ++){
//             scanf("%d",&vd[i]);
//         }

//         int ret = solution.solve(t,s,d,matrix,vs,vd);
//         printf("%d\n",ret);
//     }
// }