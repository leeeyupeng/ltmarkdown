#include"leetcode.h"

class Solution {
private:
    inline bool isconnect(vector<int>&a,vector<int>&b){
        return a[0] == b[0] || a[1] == b[1];
    }
    int find(vector<int> &us,int index){
        if(us[index] == index){return us[index];}
        us[index] = find(us,us[index]);
        return us[index];
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int ret = 0;
        vector<int> us(n,0);
        unordered_map<int,int> cmap;
        unordered_map<int,int> rmap;
        for(int i = 0; i < n; i ++){
            us[i] = i;
        }
        int c,r;
        unordered_map<int,int>::iterator cite;
        unordered_map<int,int>::iterator rite;
        for(int i = 0; i < n; i ++){
            c = stones[i][0];
            r = stones[i][1];
            cite = cmap.find(c);
            rite = rmap.find(r);
            if(cite!=cmap.end() && rite!=rmap.end()){
                us[i] = find(us,cite->second);
                us[find(us,rite->second)] = us[i]; 
            }
            else if(cite!=cmap.end()){
                us[i] = find(us,cite->second);
                rmap[r] = us[i];
            }
            else if(rite!=rmap.end()){
                us[i] = find(us,rite->second);
                cmap[c] = us[i];
            }else{

                cmap[c] = us[i];
                rmap[r] = us[i];
            }
        }
        for(int i = 0; i < n; i ++){
            if(us[i] != i){ret++;}
        }
        return ret;
    }
};

// int main(){
//     vector<vector<int>> stones={
// {0,1},{1,2},{1,3},{3,3},{2,3},{0,2}
//     };
//     Solution solution;
//     int ret = solution.removeStones(stones);
//     return 0;
// }