#include"leetcode.h"

class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int n = words.size();
        unordered_map<string,int> umap;
        vector<int> vid(n,0);
        for(int i = 0; i < n; i ++){
            if(umap.find(words[i]) == umap.end()){
                umap.insert({words[i],umap.size()});
            }
            vid[i] = umap[words[i]];
        }

        int id1 = umap[word1];
        int id2 = umap[word2];
        int ret = n;
        int lastid1 = -1,lastid2 = -1;
        for(int i = 0; i < n; i ++){
            if(vid[i] == id1){
                lastid1 = i;
                if(lastid2!=-1){ret = min(ret,lastid1 - lastid2);}                
            }
            else if(vid[i] == id2){
                lastid2 = i;
                if(lastid1 != -1){ret = min(ret,lastid2 - lastid1);}
            }
        }
        return ret;
    }
};