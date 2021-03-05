#include"leetcode.h"

class Solution {
private:    
    int find(vector<int> &us,int index){
        if(us[index]!=index){
            us[index] = find(us,us[index]);
        }
        return us[index];
    }
    bool mst(int n,int m,vector<int>& us,vector<vector<int>>& edges,vector<int> sortindex,int firstedge,int ignoreedge,int &ret){
        int counter = 0;
        for(int i = 0; i < n; i ++){us[i] = i;}
        if(firstedge!=-1){
            us[edges[firstedge][1]] = edges[firstedge][0];
            ret += edges[firstedge][2];
            counter ++;
        }
        int edgeid;
        int a,b;
        int index = 0;
        while(index<m&& counter < n - 1){
            edgeid = sortindex[index];
            index++;
            if(edgeid == ignoreedge){continue;}
            a = find(us,edges[edgeid][0]);
            b = find(us,edges[edgeid][1]);
            if(a!=b){
                ret += edges[edgeid][2];
                us[b] = a;
                counter++;
            }
        }
        if(counter == n-1){
            return true;
        }
        return false;
    }
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<int> sortindex(m,0);
        for(int i = 0; i < m; i ++){
            sortindex[i] = i;
        }
        sort(sortindex.begin(),sortindex.end(),[&edges](int a,int b){
            if(edges[a][2] == edges[b][2]){
                return a<b;
            }
            return edges[a][2] < edges[b][2];
        });
        vector<int> us(n,0);
        int minmst = 0;
        bool flag=mst(n,m,us,edges,sortindex,-1,-1,minmst);
        vector<vector<int>> ans={{},{}};
        if(flag==false){return ans;}
        int tempminmst;
        bool tempflag;        
        for(int i = 0; i < m; i ++){
            tempminmst = 0;
            tempflag = mst(n,m,us,edges,sortindex,-1,i,tempminmst);
            if(!tempflag || tempminmst != minmst){
                ans[0].push_back(i);
            }
            else{
                tempminmst = 0;
                tempflag = mst(n,m,us,edges,sortindex,i,i,tempminmst);
                if(tempflag && tempminmst == minmst){
                    ans[1].push_back(i);
                }
            }
        }
        return ans;
    }
};

// int main(){
//     int n = 4;
//     vector<vector<int>> edges={
//         {0,1,1},{0,3,1},{0,2,1},{1,2,1},{1,3,1},{2,3,1}
//     };

//     Solution solution;
//     auto ans = solution.findCriticalAndPseudoCriticalEdges(n,edges);
//     return 0;
// }