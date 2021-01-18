#include"leetcode.h"

int us[1001];
int cmap[10001];
int rmap[10001];
class Solution {
private:
    inline bool isconnect(vector<int>&a,vector<int>&b){
        return a[0] == b[0] || a[1] == b[1];
    }
    int find(int index){
        if(us[index] == index){return us[index];}
        us[index] = find(us[index]);
        return us[index];
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int ret = 0;
        memset(cmap,-1,10001*sizeof(int));
        memset(rmap,-1,10001*sizeof(int));
        for(int i = 0; i < n; i ++){
            us[i] = i;
        }
        int c,r;
        for(int i = 0; i < n; i ++){
            c = stones[i][0];
            r = stones[i][1];

            if(cmap[c]!=-1 && rmap[r]!=-1){
                us[i] = find(cmap[c]); //这一句写成us[i] = cmap[c];会有问题，当cmap[c]和rmap[r]同属一个集合时;所有并查集合并是一定要进行根合并
                us[find(rmap[r])] = us[i]; 
            }
            else if(cmap[c]!=-1){
                us[i] = cmap[c];
                rmap[r] = us[i];
            }
            else if(rmap[r]!=-1){
                us[i] = rmap[r];
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