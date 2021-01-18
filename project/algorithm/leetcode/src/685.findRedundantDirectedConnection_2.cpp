#include"leetcode.h"

class Solution {
private:
    int find(vector<int>& us,int index){
        if(us[index] == index){
            return us[index];
        }
        us[index] = find(us,us[index]);
        return us[index];
    }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> us(n+1,0);
        for(int i = 0; i <= n; i ++){
            us[i] = i;
        }
        vector<int> degree(n+1,0);
        int degreesecondindex = -1;
        for(int i = 0; i < n; i ++){
            degree[edges[i][1]] ++;
            if(degree[edges[i][1]] == 2){
                degreesecondindex = edges[i][1];
            }
        }
        degree.clear();
        vector<int> degreesecondedges;
        int a,b;
        for(int i = 0; i < n; i ++){
            a = find(us,edges[i][0]);
            b = find(us,edges[i][1]);
            if(edges[i][1] == degreesecondindex){
                degreesecondedges.push_back(i);
            }
            else if(a==b){
                return edges[i];
            }
            else{
                us[b] = a;
            }
        }
        int edgeid;
        for(int i = 0; i < 2; i ++){
            edgeid = degreesecondedges[i];
            a = find(us,edges[edgeid][0]);
            b = find(us,edges[edgeid][1]);
            if(a==b){
                return edges[edgeid];
            }
            else{
                us[b] = a;
            }
        }
        return {};
    }
};