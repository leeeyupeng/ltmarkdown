#include"hdu.h"

class Solution{
private:
    int dijkstra(int n,vector<vector<int>>& matrix,int s,int t){
        vector<char> visit(n,0);
        auto cmp = [](pair<int,int> &a,pair<int,int> &b){
            if(a.second == b.second){
                return a.first > b.first;
            }
            return a.second > b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
        pq.push({s,0});
        pair<int,int> top;
        vector<int> mindistance(n,INT_MAX);
        while(!pq.empty()){
            top = pq.top();
            pq.pop();
            if(visit[top.first] == 1){continue;}
            if(top.first == t) {return top.second;}
            visit[top.first] = 1;
            for(int i = 0; i < n; i ++){
                if(visit[i] == 0 && matrix[top.first][i] != INT_MAX && mindistance[i] > top.second + matrix[top.first][i]){
                    mindistance[i] = top.second + matrix[top.first][i];
                    pq.push({i,mindistance[i]});
                }
            }
        }
        return INT_MAX;
    }
public:
    int Solve(int n,int m,vector<vector<int>>& matrix){
        int temp;
        int ret = INT_MAX;
        int distij;
        for(int i = 0; i < n; i ++){
            for(int j = i+1; j < n; j ++){
                if(matrix[i][j]!=INT_MAX){
                    temp = matrix[i][j];
                    matrix[i][j] = INT_MAX;
                    matrix[j][i] = INT_MAX;
                    distij = dijkstra(n,matrix,i,j);
                    if(distij!=INT_MAX){
                        ret = min(ret,temp + distij);
                    }
                }
            }
        }
        return ret;
    }    
};

// int main(){
//     int n,m;
//     int a,b,c;
//     while(scanf("%d%d",&n,&m)!=EOF){
//         vector<vector<int>> matrix(105,vector<int>(105,INT_MAX));
//         for(int i = 0; i < m; i++){
//             scanf("%d%d%d",&a,&b,&c);
//             a--;
//             b--;
//             // a = rand() % n;
//             // b = rand() % n;
//             // while(a == b){
//             //    b = rand() % n; 
//             // }
//             // c = rand() % 100 + 1;
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

//     return 0;
// }