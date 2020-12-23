#include"hdu.h"
class Solution{
private:
public:
    int shortestpath(int n,int m,vector<vector<int>>& matrix,int s,int e){
        vector<int> distance(n+1,1000000);
        distance[s] = 0;
        bool flag = true;
        for(int k = 1; k <= n; k ++){
            flag = false;
            for(int i = 1;i <= n; i ++){
                for(int j = i+1;j <= n; j ++){
                    if(matrix[i][j] != 0){
                        if(distance[j] > distance[i] + matrix[i][j]){
                            distance[j] = distance[i] + matrix[i][j];
                            flag = true;
                        }
                        if(distance[i] > distance[j] + matrix[i][j]){
                            distance[i] = distance[j] + matrix[i][j];
                            flag = true;                            
                        }
                    }
                }
            }
            if(flag==false){break;}
        }
        return distance[e];
    }
};

// int main(){
//     int n,m;
//     Solution solution;
//     while(scanf("%d%d",&n,&m)){
//         if(n==0&&m==0){break;}
//         vector<vector<int>> matrix(n+1,vector<int>(n+1,0));
//         int s,e,cost;
//         for(int i = 0; i < m; i ++){
//             scanf("%d%d%d",&s,&e,&cost);
//             // s = rand()%n+1;
//             // e = rand()%n+1;
//             matrix[s][e]=cost;
//             matrix[e][s] = cost;
//         }

//         int ret = solution.shortestpath(n,m,matrix,1,n);
//         printf("%d\n",ret);
//     }
//     return 0;
// }