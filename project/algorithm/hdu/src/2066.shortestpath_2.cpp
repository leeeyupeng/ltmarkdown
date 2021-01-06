#include"hdu.h"

#define NMAX 1000

struct EdgeNode{
    int s;
    int t;
    int time;
    EdgeNode(int _s,int _t,int _time):s(_s),t(_t),time(_time){}
};
class Solution{
private:
    void floyd(int t,vector<EdgeNode>& edges,vector<vector<int>>& matrix){
        EdgeNode* edge = nullptr;
        bool flag = true;

        for(int k = 0; k < t;k++){
            edge = &(edges[k]);      
            for(int i = 1; i <= NMAX; i ++){
                for(int j = 1; j <= NMAX;j ++){
                    if(matrix[i][edge->s]!=-1&&matrix[edge->t][j]!=-1){
                        if(matrix[i][j] == -1){
                            matrix[i][j] = matrix[i][edge->s] + edge->time + matrix[edge->t][j];
                            matrix[j][i] = matrix[i][j];
                        }
                        else if(matrix[i][j] > matrix[i][edge->s] + edge->time + matrix[edge->t][j]){
                            matrix[i][j] = matrix[i][edge->s] + edge->time + matrix[edge->t][j];
                            matrix[j][i] = matrix[i][j];
                        }
                    }
                }
            }
        }
        
    }
public:
    int solve(int t,int s,int d,vector<EdgeNode>& edges,vector<vector<int>>& matrix,vector<int>& vs,vector<int>& vd){
        floyd(t,edges,matrix);
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
//         vector<EdgeNode> edges(t,{0,0,0});
//         vector<vector<int>> matrix(NMAX+1,vector<int>(NMAX+1,-1));
//         for(int i = 1; i <= NMAX; i ++){
//             matrix[i][i] = 0;
//         }
//         for(int i = 0; i < t; i ++){
//             scanf("%d%d%d",&a,&b,&time);
//             if(matrix[a][b] == -1 || matrix[a][b] > time){
//                 matrix[a][b] = time;
//                 matrix[b][a] = time;
//             }

//             edges[i] = {a,b,time};
//         }

//         vector<int> vs(s);
//         for(int i = 0; i < s; i ++){
//             scanf("%d",&vs[i]);
//         }
//         vector<int> vd(d);
//         for(int i = 0; i < d; i ++){
//             scanf("%d",&vd[i]);
//         }

//         int ret = solution.solve(t,s,d,edges,matrix,vs,vd);
//         printf("%d\n",ret);
//     }
// }