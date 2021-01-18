#include"leetcode.h"

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<int> ndegress(n,0);
        vector<int> mdegress(m,0);
        vector<int> vertices(n,-1);
        vector<pair<int,int>> edges;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < beforeItems[i].size();j ++){
                edges.push_back({i,vertices[beforeItems[i][j]]});
                vertices[beforeItems[i][j]] = edges.size()-1;
                ndegress[i]++;
                if(group[i]!=-1 && group[i] != group[beforeItems[i][j]]){
                    mdegress[group[i]] ++;
                }
            }
        }
        vector<vector<int>> mdegresszero(m);
        vector<int> degresszero;
        for(int i = 0; i < n; i ++){
            if(ndegress[i] == 0){
                if(group[i] == -1){
                    degresszero.push_back(i);
                }
                else{
                    mdegresszero[group[i]].push_back(i);
                }
            }
        }
        queue<int> q;
        for(int i = 0; i < m; i ++){
            if(mdegress[i] == 0){
                q.push(i);
            }
        }
        vector<int> ans;
        vector<int> *zero;
        int index;
        int groupid;
        int edgeid;
        int edget;
        int edgegroupid;
        while(!q.empty() || !degresszero.empty()){
            if(!q.empty()){
                zero = &mdegresszero[q.front()];
                q.pop();
            }
            else{
                zero = &degresszero;
            }

            while(!zero->empty()){
                index = zero->back();
                zero->pop_back();
                groupid = group[index];
                ans.push_back(index);
                edgeid = vertices[index];
                while(edgeid!=-1){
                    edget = edges[edgeid].first;
                    edgegroupid = group[edget];
                    ndegress[edget] --;
                    if(ndegress[edget] == 0){
                        if(edgegroupid==-1){
                            degresszero.push_back(edget);
                        }
                        else{
                            mdegresszero[edgegroupid].push_back(edget);
                        }
                    }
                    if(edgegroupid!=-1 && groupid!=edgegroupid){
                        mdegress[edgegroupid] --;
                        if(mdegress[edgegroupid] == 0){
                            q.push(edgegroupid);
                        }
                    }
                    edgeid = edges[edgeid].second;
                }
            }
        }

        if(ans.size()!=n){
            return vector<int>();
        }
        return ans;
    }
};