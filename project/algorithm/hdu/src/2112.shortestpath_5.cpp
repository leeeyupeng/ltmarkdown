#include"hdu.h"

#define CHARNUMS 256
#define VERTICEMAX 152
#define MAXLENGTH 32
#define TIMEMAX 101
class Solution{

public:
    int getshotestpath(int matrix[VERTICEMAX][VERTICEMAX],char visit[],int distance[],int cnt,int start,int end){
        distance[start] = 0;
        int minindex;
        for(int k = 0; k < cnt; k ++){
            minindex = -1;
            for(int i = 0; i < cnt; i ++){
                if(visit[i] == 0 && distance[i] != -1){
                    if(minindex == -1){
                        minindex = i;
                    }
                    else if(distance[i] < distance[minindex]){
                        minindex = i;
                    }
                }
            }
            if(minindex == -1){break;}
            visit[minindex] = 1;
            if(minindex==end){
                break;
            }
            for(int i=0 ; i < cnt; i ++){
                if(visit[i] == 0 && matrix[minindex][i]!= -1){
                    if(distance[i] == -1 || distance[i] > distance[minindex] + matrix[minindex][i]){
                        distance[i] = distance[minindex] + matrix[minindex][i];
                    }
                }
            }
        }
        return distance[end];
    }
};

int matrix[VERTICEMAX][VERTICEMAX];
std::map<string,int> triemap;
char visit[VERTICEMAX];
int dist[VERTICEMAX];

// int main()
// {
//     ios::sync_with_stdio(0);
//     int n;
//     Solution solution;

//     while(cin>>n){
//         if(n==-1){break;}

//         int cnt = 0;

//         triemap.clear();
//         string start,end;
//         cin>>start>>end;
//         if(triemap.find(start) == triemap.end()){triemap.insert({start,cnt++});}
//         if(triemap.find(end) == triemap.end()){triemap.insert({end,cnt++});}
//         int startid = triemap[start];
//         int endid = triemap[end];

//         memset(matrix,INFINITY,sizeof(matrix));
//         memset(visit,0,sizeof(visit));
//         memset(dist,INFINITY,sizeof(dist));
        
//         int t;
//         int sid;
//         int eid;
//         for(int i = 0; i < n; i ++){ 
//             string s,e;              
//             cin>>s>>e>>t;        
//             if(triemap.find(s) == triemap.end()){triemap.insert({s,cnt++});}
//             if(triemap.find(e) == triemap.end()){triemap.insert({e,cnt++});}
//             sid = triemap[s];
//             eid = triemap[e];
//             if(matrix[sid][eid] == -1){
//                 matrix[sid][eid] = t;
//             }
//             else{
//                 matrix[sid][eid] = min(matrix[sid][eid],t);
//             }
//             matrix[eid][sid] = matrix[sid][eid];
//         }
//         for(int i = 0; i < cnt; i ++){
//             matrix[i][i] = 0;
//         }
//         int ret = solution.getshotestpath(matrix,visit,dist,cnt,startid,endid);

//         cout<<ret<<endl;
//     }
//     return 0;
// }