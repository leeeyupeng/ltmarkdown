#include"hdu.h"

#define CHARNUMS 256
#define VERTICEMAX 152
#define MAXLENGTH 32
#define TIMEMAX 101
class Solution{
public:
    int getshotestpath(vector<vector<int>>& matrix,int cnt,int start,int end){
        vector<int> distance(cnt,INT_MAX);
        distance[start] = 0;
        for(int i = 0; i < cnt; i ++){
            distance[i] = min(distance[i],matrix[start][i]);
        }
        bool flag = true;
        for(int k = 0; k < cnt; k ++){
            flag = false;
            for(int i = 0; i < cnt; i ++){
                for(int j = 0; j < cnt; j ++){
                    if(distance[i] != INT_MAX && matrix[i][j]!= INT_MAX){
                        distance[j] = min(distance[j],distance[i] + matrix[i][j]);
                        flag = true;
                    }
                }
            }
            if(flag==false){break;}
        }
        if(distance[end] == INT_MAX){
            return -1;
        }
        return distance[end];
    }
};
// int main()
// {
//     int n;
//     Solution solution;
//     vector<vector<int>> matrix(VERTICEMAX,vector<int>(VERTICEMAX,INT_MAX));
//     map<string,int> map;
//     while(scanf("%d",&n)!=EOF){
//         if(n==-1){break;}

//         int cnt = 0;

//         map.clear();
//         string start,end;
//         cin>>start>>end;
//         if(map.find(start) == map.end()){map.insert({start,cnt++});}
//         if(map.find(end) == map.end()){map.insert({end,cnt++});}
//         int startid = map[start];
//         int endid = map[end];

//         for(int i = 0; i < VERTICEMAX; i ++){
//             for(int j = 0; j < VERTICEMAX; j ++){
//                 matrix[i][j] = INT_MAX;
//             }
//         }
//         for(int i = 0; i < VERTICEMAX; i ++){
//             matrix[i][i] = 0;
//         }
//         int t;
//         int sid;
//         int eid;
//         for(int i = 0; i < n; i ++){ 
//             string s,e;              
//             cin>>s>>e>>t;        
//             if(map.find(s) == map.end()){map.insert({s,cnt++});}
//             if(map.find(e) == map.end()){map.insert({e,cnt++});}
//             sid = map[s];
//             eid = map[e];
//             matrix[sid][eid] = min(matrix[sid][eid],t);
//             matrix[eid][sid] = matrix[sid][eid];
//         }
//         int ret = solution.getshotestpath(matrix,cnt,startid,endid);

//         printf("%d\n",ret);
//     }
//     return 0;
// }