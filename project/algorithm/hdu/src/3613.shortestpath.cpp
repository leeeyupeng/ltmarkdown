#include"hdu.h"

class Solution{
private:
    int n,m;
    vector<vector<int>> matrix;
    vector<char> vflag;
public:
    void init(int n,int m,vector<vector<int>>& matrix){
        this->n = n;
        this->m = m;
        this->matrix = matrix;
        vflag = vector<char>(n,0);

    }

    void floyd(int x){
        for(int i = 0; i< n; i ++){
            for(int j = 0; j < n; j ++){
                if(matrix[i][x] != -1 && matrix[x][j] != -1){
                    if(matrix[i][j] == -1){
                        matrix[i][j] = matrix[i][x] + matrix[x][j];
                    }
                    else if(matrix[i][j] > matrix[i][x] + matrix[x][j]){
                        matrix[i][j] = matrix[i][x] + matrix[x][j];
                    }
                }
            }
        }
    }

    int operation0(int x){
        if(vflag[x] == 1){return -1;}
        vflag[x] = 1;
        floyd(x);
        return 1;
    }
    int operation1(int x,int y){
        if(vflag[x] == 0 || vflag[y] == 0){return -2;}
        return matrix[x][y];
    }
};

// int main(){
//     int n,m,q;
//     int x,y,c;
//     int operation;
//     int testcount = 0;

//     while(scanf("%d%d%d",&n,&m,&q)){
//         if(n==0&&m==0&&q == 0){
//             break;
//         }
//         if(testcount!=0){
//             printf("\n");
//         }
//         Solution solution;
//         vector<vector<int>> matrix(n,vector<int>(n,-1));
//         testcount++;
//         printf("Case %d:\n",testcount);
//         for(int i = 0; i < m; i ++){
//             scanf("%d%d%d",&x,&y,&c);
//             if(matrix[x][y] == -1){
//                 matrix[x][y] = c;
//             }
//             else if(matrix[x][y] > c){
//                 matrix[x][y] = c;
//             }
//         }
//         for(int i = 0; i < n; i ++){
//             matrix[i][i] = 0;
//         }
//         solution.init(n,m,matrix);
//         for(int i = 0; i < q; i ++){
//             scanf("%d",&operation);
//             if(operation==0){
//                 scanf("%d",&x);
//                 int ret = solution.operation0(x);
//                 if(ret == -1){
//                     printf("ERROR! At point %d\n",x);
//                 }
//             }
//             else{
//                 scanf("%d%d",&x,&y);

//                 int ret = solution.operation1(x,y);
//                 if(ret == -2){
//                     printf("ERROR! At path %d to %d\n",x,y);
//                 }
//                 else if(ret == -1){
//                     printf("No such path\n");
//                 }
//                 else{
//                     printf("%d\n",ret);
//                 }
//             }
//         }
//     }
//     return 0;
// }