#include"leetcode.h"

class Solution {
private:
    int find(vector<int> &us,int index){
        if(us[index]!=index){us[index] = find(us,us[index]);}
        return us[index];
    }
    void uni(vector<int> &us,int a,int b){
        a = find(us,a);
        b = find(us,b);
        if(a!=b){
            us[b] = a ; 
        }
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> us(n,0);
        for(int i = 0; i < n; i ++){us[i] = i;}
        map<string,int> umap;
        for(int i = 0; i < n; i ++){
            for(int j = 1;j < accounts[i].size();j ++){
                if(umap.find(accounts[i][j])!=umap.end()){
                    uni(us,umap[accounts[i][j]],i);
                }
                else{
                    umap[accounts[i][j]] = i;
                }
            }
        }

        unordered_map<int,int> retmap;
        vector<vector<string>> ret;
        int index;
        for(map<string,int>::iterator ite = umap.begin(); ite!=umap.end();ite++){
            index = find(us,ite->second);
            if(retmap.find(index)==retmap.end()){
                ret.push_back({accounts[index][0]});
                retmap[index] = ret.size() - 1;
            }
            ret[retmap[index]].push_back(ite->first);
        }

        return ret;
    }
};