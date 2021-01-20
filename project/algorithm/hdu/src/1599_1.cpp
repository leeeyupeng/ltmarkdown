#include"hdu.h"

class Solution{
public:

    int Solve(vector<vector<int>> matrix,int start){
        int n = matrix.size();
        vector<vector<char>> visit(n,vector<char>(n,0));
        vector<int> mindistance(n,INT_MAX);
        
        auto cmp = [](pair<int,int> &a,pair<int,int> &b){
            if(a.second == b.second){
                return a.first > b.first;
            }
            return a.second > b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
        mindistance[start] = 0;
        pq.push({start,0});
        
    }
    
};

// int main(){
//     int n,m;
//     int a,b,c;
//     while(scanf("%d%d",&n,&m)!=EOF){
//         vector<vector<int>> matrix(n,vector<int>(n,INT_MAX));
//         for(int i = 0; i < m; i++){
//             scanf("%d%d%d",&a,&b,&c);
//             matrix[a][b] = min(matrix[a][b],c);
//             matrix[a][b] = matrix[b][a];
//         }

//         Solution solution;
//         int ret = solution.Solve(matrix);
//     }
// }