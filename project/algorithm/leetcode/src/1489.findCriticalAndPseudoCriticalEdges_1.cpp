#include"leetcode.h"

class Solution {
private:
    struct  cmp
    {
        bool operator()(pair<int,vector<int>> &a,pair<int,vector<int>> &b){
            if(a.second[2] == b.second[2]){
                return a.first > b.first;
            }
            return a.second[2] > b.second[2];
        };
    };
    
    int find(vector<int> &us,int index){
        if(us[index]!=index){
            us[index] = find(us,us[index]);
        }
        return us[index];
    }
    bool mst(int n,vector<int>& us,priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,cmp> &pq,int counter,int &ret){
        pair<int,vector<int>> top;
        int a,b;
        while(!pq.empty() && counter < n - 1){
            top = pq.top();
            pq.pop();
            a = find(us,top.second[0]);
            b = find(us,top.second[1]);
            if(a!=b){
                ret += top.second[2];
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
        
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,cmp> pq;
        for(int i = 0; i < m; i ++){
            pq.push({i,edges[i]});
        }
        vector<int> us(n,0);
        for(int i = 0; i<n; i ++){us[i]=i;}
        int minmst = 0;    
        bool flag = mst(n,us,pq,0,minmst);
        if(flag==false){return {};}
        vector<int> critical;
        vector<int> pseudo;
        bool tempflag;
        int tempminmst=0;
        for(int k = 0; k < m; k ++){
            while(!pq.empty()){pq.pop();}
            for(int i = 0; i < m; i ++){
                if(i != k){
                    pq.push({i,edges[i]});                    
                }
            }               
            for(int i = 0; i<n; i ++){us[i]=i;}
            us[edges[k][1]] = edges[k][0];
            tempminmst = edges[k][2];
            tempflag = mst(n,us,pq,1,tempminmst);
            if(tempflag == true && tempminmst == minmst){                
                while(!pq.empty()){pq.pop();}
                for(int i = 0; i < m; i ++){
                    if(i != k){
                        pq.push({i,edges[i]});                    
                    }
                }
                for(int i = 0; i<n; i ++){us[i]=i;}
                tempminmst = 0;
                tempflag = mst(n,us,pq,0,tempminmst);
                if(tempflag == true && tempminmst == minmst){ 
                    pseudo.push_back(k);
                }
                else{
                    critical.push_back(k);
                }
            }
            else{

            }           

        }

        vector<vector<int>> ans;
        ans.push_back(critical);
        ans.push_back(pseudo);
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