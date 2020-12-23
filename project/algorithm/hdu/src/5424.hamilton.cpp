#include"hdu.h"

class Solution {
private:
    int n;
    struct EdgeNode {
        int target;
        EdgeNode *next;
        EdgeNode() : target(0), next(nullptr) {}
        EdgeNode(int _target) : target(_target), next(nullptr) {}
        EdgeNode(int _target, EdgeNode *next) : target(_target), next(next) {}
    };
    bool dfs(vector<EdgeNode*>& verticeedge,vector<EdgeNode>& edgenodes,vector<char>& visit,int vertice,int visitcounter){
        if(visitcounter + 1 == n){
            return true;
        }
        visit[vertice] = 1;
        EdgeNode* node= verticeedge[vertice];
        while(node!=nullptr){
            if(visit[node->target] == 0){
                if(dfs(verticeedge,edgenodes,visit,node->target,visitcounter+1)){
                    return true;
                }
            }
            node=node->next;
        }
        visit[vertice] = 0;
        return false;
    }
public:
    bool hamiltonian(int n,vector<int[2]>& edges) {
        this->n = n;
        int mindegreesvertice = 1;
        {
            vector<char> degrees(n+1,0);
            for(int i = 0; i < n; i ++){
                degrees[edges[i][0]]++;
                degrees[edges[i][1]]++;
            }
            
            int onenums = 0;
            for(int i = 1; i <= n; i ++){
                if(degrees[i] < degrees[mindegreesvertice]){
                    mindegreesvertice = i;
                }
                // if(degrees[i] > 3){
                //     return false;
                // }
                if(degrees[i] == 0){
                    return false;
                }
                if(degrees[i] == 1){
                    onenums++;
                    if(onenums>2){
                        return false;
                    }
                }
            }
            degrees.clear();
        }

        vector<EdgeNode*> verticeedge(n+1,nullptr);
        vector<EdgeNode> edgenodes(n<<1);
        for(int i = 0; i < n; i ++){
            edgenodes[(i<<1)].target = edges[i][1];
            edgenodes[(i<<1)].next = verticeedge[edges[i][0]];
            verticeedge[edges[i][0]] = &edgenodes[(i<<1)];

            edgenodes[(i<<1)+1].target = edges[i][0];
            edgenodes[(i<<1)+1].next = verticeedge[edges[i][1]];
            verticeedge[edges[i][1]] = &edgenodes[(i<<1)+1];
        }
        vector<char> visit(n+1,0);
        return dfs(verticeedge,edgenodes,visit,mindegreesvertice,0);
    }
};

// int main(){
//     int n;
//     int u,v;
//     Solution solution;
//     while(scanf("%d",&n)!=-1){
//         vector<int[2]> edges(n);
//         for(int i = 0; i < n; i ++){
//             scanf("%d%d",&edges[i][0],&edges[i][1]);
//         }

//         bool ret = solution.hamiltonian(n,edges);
//         printf(ret?"YES":"NO");
//         printf("\n");
//     }
//     return 0;
// }