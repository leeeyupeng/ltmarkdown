#include"hdu.h"

#define CHARNUMS 256
#define VERTICEMAX 152
#define MAXLENGTH 32
#define TIMEMAX 101
class Solution{
public:
    int getshotestpath(vector<vector<int>>& matrix,int start,int end){
        auto cmp = [](pair<int,int>& a,pair<int,int>& b){
            if(a.second == b.second){
                return a.first > b.first;
            }

            return a.second > b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
        pq.push({start,0});

        vector<char> visit(VERTICEMAX,0);
        pair<int,int> top;
        while(!pq.empty()){
            top = pq.top();
            pq.pop();
            visit[top.first] = 1;
            if(top.first == end){
                return top.second;
            }

            for(int i = 0; i < VERTICEMAX; i ++){
                if(visit[i] == 0 && matrix[top.first][i]!=INT_MAX)
                {                    
                    pq.push({i,top.second + matrix[top.first][i]});
                }
            }
        }


        return -1;
    }
};
// int main()
// {
//     int n;
//     while(scanf("%d",&n)!=EOF){
//         if(n==-1){break;}
        
//         Solution solution;

//         int cnt = 0;
//         map<string,int> map;
//         string start,end;
//         cin>>start>>end;
//         if(map.find(start) == map.end()){map.insert({start,cnt++});}
//         if(map.find(end) == map.end()){map.insert({end,cnt++});}
//         int startid = map[start];
//         int endid = map[end];

//         vector<vector<int>> matrix(VERTICEMAX,vector<int>(VERTICEMAX,INT_MAX));
        
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
//         int ret = solution.getshotestpath(matrix,startid,endid);

//         printf("%d\n",ret);
//     }
//     return 0;
// }