#include"hdu.h"

class Solution{
private:
public:
    pair<int,int> shortestpath(int n,int m,vector<vector<pair<int,int>>>& matrix,int s,int t){
        vector<pair<int,int>> distance(n+1,{INT_MAX,INT_MAX});
        distance[s].first = 0;
        distance[s].second = 0;
        bool flag = true;
        for(int k = 1; k <= n; k ++){
            flag = false;
            for(int i = 1;i <= n; i ++){
                for(int j = i+1;j <= n; j ++){
                    if(matrix[i][j].first != -1){
                        if(distance[i].first != INT_MAX && distance[j].first > distance[i].first + matrix[i][j].first){
                            distance[j].first = distance[i].first + matrix[i][j].first;
                            distance[j].second = distance[i].second + matrix[i][j].second;
                            flag = true;
                        }
                        else if(distance[i].first != INT_MAX && distance[j].first == distance[i].first + matrix[i][j].first){
                            if(distance[i].second!=INT_MAX&&distance[j].second > distance[i].second + matrix[i][j].second){
                                distance[j].second = distance[i].second + matrix[i][j].second;
                                flag = true;
                            }
                        }
                        if(distance[j].first != INT_MAX && distance[i].first > distance[j].first + matrix[i][j].first){
                            distance[i].first = distance[j].first + matrix[i][j].first;
                            distance[i].second = distance[j].second + matrix[i][j].second;
                            flag = true;
                        }
                        else if(distance[j].first != INT_MAX && distance[i].first == distance[j].first + matrix[i][j].first){
                            if(distance[j].second!=INT_MAX&&distance[i].second > distance[j].second + matrix[i][j].second){
                                distance[i].second = distance[j].second + matrix[i][j].second;
                                flag = true;
                            }
                        }
                    }
                }
            }
            if(flag==false){break;}
        }
        return distance[t];
    }
};

// int main(){
//     int n,m;
//     Solution solution;
//     while(scanf("%d%d",&n,&m)){
//         if(n==0&&m==0){break;}
//         vector<vector<pair<int,int>>> matrix(n+1,vector<pair<int,int>>(n+1,{-1,0}));
//         int s,t,d,p;
//         for(int i = 0; i < m; i ++){
//             scanf("%d%d%d%d",&s,&t,&d,&p);
//             // s = rand()%n+1;
//             // e = rand()%n+1;
//             if(matrix[s][t].first == -1){
//                 matrix[s][t]={d,p};
//                 matrix[t][s] ={d,p};
//             }
//             else if(matrix[s][t].first > d){
//                 matrix[s][t]={d,p};
//                 matrix[t][s] ={d,p};
//             }
//             else if(matrix[s][t].first == d && matrix[s][t].second > p){
//                 matrix[s][t]={d,p};
//                 matrix[t][s] ={d,p};
//             }
//         }

//         scanf("%d%d",&s,&t);
//         pair<int,int> ret = solution.shortestpath(n,m,matrix,s,t);
//         printf("%d %d\n",ret.first,ret.second);
//     }
//     return 0;
// }