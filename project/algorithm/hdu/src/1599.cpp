#include"hdu.h"

class Solution{
public:
    struct Edge
    {
        int t;
        int c;
        int next;
        Edge(int _t,int _c):t(_t),c(_c),next(-1){}
    };

    int Solve(vector<int> &vertice,vector<Edge> &edges){
        int n = vertice.size();
        vector<char> visit(n,0);
        
    }
    
};

// int main(){
//     int n,m;
//     int a,b,c;
//     while(scanf("%d%d",&n,&m)!=EOF){
//         vector<int> vertice(n,-1);
//         vector<Solution::Edge> edges(m*2);
//         for(int i = 0; i < m; i ++){
//             scanf("%d%d%d",&a,&b,&c);
//             edges[(i<<1)] = {b,c};
//             edges[(i<<1)].next = vertice[a];
//             vertice[a] = (i<<1);

//             edges[(i<<1)+1] = {a,c};
//             edges[(i<<1)+1].next = vertice[b];
//             vertice[b] = (i<<1) + 1;
//         }
//     }
// }