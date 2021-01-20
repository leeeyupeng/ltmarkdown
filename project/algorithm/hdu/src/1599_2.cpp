#include"hdu.h"

class Solution{
private:
    int floyd(int n,int m,vector<vector<int>>& matrix,int index){
        vector<vector<int>> matrix2 = matrix;
        for(int k = 0; k < n; k ++){
            if(k!=index){
                for(int i = 0; i < n; i ++){
                    for(int j = i+1; j < n; j ++){
                        if(i != k && j != k && matrix2[i][k]!= INT_MAX &&  matrix2[k][j]!=INT_MAX){
                            matrix2[i][j] = min(matrix2[i][j],matrix2[i][k] + matrix2[k][j]);
                            matrix2[j][i] = matrix2[i][j];
                        }
                    }
                }
            }
        }
        int ret = INT_MAX;
        for(int i = 0; i < n;i ++){
            for(int j = i+1; j < n;j ++){
                if(i != j && i != index && j != index && matrix[index][i] != INT_MAX &&  matrix2[i][j] != INT_MAX && matrix[j][index]!= INT_MAX){
                    ret = min(ret,matrix[index][i] + matrix2[i][j] + matrix[j][index]);
                }
            }
        }
        return ret;
    }
public:
    int Solve(int n,int m,vector<vector<int>>& matrix){
        int ret = INT_MAX;
        for(int i = 0; i < n; i ++){
            ret = min(ret,floyd(n,m,matrix,i));
        }   
        return ret;
    }
    
};

// int main(){
//     int n,m;
//     int a,b,c;
//     while(scanf("%d%d",&n,&m)!=EOF){
//         vector<vector<int>> matrix(n,vector<int>(n,INT_MAX));
//         for(int i = 0; i < m; i++){
//             //scanf("%d%d%d",&a,&b,&c);
//             // a--;
//             // b--;
//             a = rand() % n;
//             b = rand() % n;
//             while(a == b){
//                b = rand() % n; 
//             }
//             c = rand() % 100;
//             matrix[a][b] = min(matrix[a][b],c);
//             matrix[b][a] = matrix[a][b];
//         }

//         Solution solution;
//         int ret = solution.Solve(n,m,matrix);
//         if(ret == INT_MAX){
//             printf("It's impossible.\n");
//         }
//         else{
//             printf("%d\n",ret);
//         }
//     }
// }