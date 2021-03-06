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
    bool hamilton(vector<EdgeNode*>& verticeedge,vector<EdgeNode>& edgenodes,vector<char>& visit,int vertice,int vertice2){
        int head = vertice;
        int end = vertice2;
        visit[head] = 1;
        visit[end] = 1;
        EdgeNode* edge;
        bool flag = true;
        int target=0;
        int targetnums = 0;
        while(flag){
            edge = verticeedge[end];
            flag = false;
            targetnums = 0;
            while(edge!=nullptr){
                if(visit[edge->target]==0){
                    target = edge->target;
                    targetnums ++;
                }
                edge = edge->next;
            }
            if(targetnums == 1){
                end = target;   
                visit[target] = 1;                 
                flag = true;
            }
        }
        if(vertice == vertice2){
            head = end;
        }
        flag = true;
        while(flag){
            edge = verticeedge[head];
            flag = false;
            while(edge!=nullptr){
                if(visit[edge->target]==0){
                    head = edge->target;
                    visit[edge->target] = 1;
                    flag = true;
                    break;
                }
                edge = edge->next;
            }
        }

        for(int i = 1;  i <= n; i ++){
            if(visit[i] == 0){return false;}
        }

        if(vertice == vertice2){
            return true;
        }
        edge = verticeedge[head];
        while(edge!=nullptr){
            if(edge->target == end){return true;}
            edge = edge->next;
        }
        return false;
    }
public:
    bool hamiltonian(int n,vector<int[2]>& edges) {
        this->n = n;
        int mindegreesvertice = 1;
        int mindegreesvertice2 = 1;
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
                    if(onenums == 0){
                        mindegreesvertice = i;
                        mindegreesvertice2 = i;
                    }
                    else{
                        mindegreesvertice2 = i;
                    }
                    onenums++;
                    if(onenums>2){
                        return false;
                    }
                }
            }
            degrees.clear();

            // if(mindegreesvertice == mindegreesvertice2){
            //     for(int i = 1; i <= n; i ++){
            //         if(mindegreesvertice!=i){
            //             mindegreesvertice2 = i;
            //             break;
            //         }
            //     }
            // }
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
        return hamilton(verticeedge,edgenodes,visit,mindegreesvertice,mindegreesvertice2);
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