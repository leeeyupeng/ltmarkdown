#include"leetcode.h"

#define MAX 101
class Solution {
private:
    int nvindex;
    vector<vector<int>> vindex;
    inline int getg(vector<vector<int>>& cuboids,int w,int l,int h){
        int n = cuboids.size();
        int ret = 0;
        int reth = 0;
        int ww,ll,hh;
        for(int i = 0; i < n; i ++){
            reth = 0;
            for(int wlh = 0; wlh < nvindex; wlh ++){
                ww = cuboids[i][vindex[wlh][0]],ll=cuboids[i][vindex[wlh][1]],hh = cuboids[i][vindex[wlh][2]];
                if(ww<=w&&ll<=l&&hh<=h){
                    reth = max(reth,hh);
                }
            }
            ret += reth;
        }
        return ret;
    }
    inline int getkey(int w,int l,int h){
        return w * MAX * MAX + l * MAX + h;
    }
    inline void initequal(vector<vector<int>>& cuboids,vector<int>& vequal){
        int n = cuboids.size();
        int ww,ll,hh;
        int key;
        unordered_set<int> us;
        for(int i = 0; i < n; i ++){
            us.clear();
            for(int wlh = 0; wlh < nvindex; wlh ++){
                ww = cuboids[i][vindex[wlh][0]],ll=cuboids[i][vindex[wlh][1]],hh = cuboids[i][vindex[wlh][2]];
                key = getkey(ww,ll,hh);
                if(us.find(key)==us.end()){
                    vequal[key] += hh;
                    us.insert(key);
                }
                else{
                    
                }
            }
        }
    }
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        nvindex = 6;
        vindex = {
            {0,1,2},
            {0,2,1},
            {1,0,2},
            {1,2,0},
            {2,0,1},
            {2,1,0}
        };
        vector<int> vg(MAX * MAX * MAX +  MAX * MAX  + MAX + 1,0);

        vector<int> vequal(MAX * MAX * MAX +  MAX * MAX  + MAX + 1,0);
        
        int key;
        int kkey;
        int w,l,h;
        int ww,ll,hh;
        for(int i = 0; i < n; i ++){
            for(int wlh = 0; wlh < nvindex; wlh ++){
                w = cuboids[i][vindex[wlh][0]];l = cuboids[i][vindex[wlh][1]];h = cuboids[i][vindex[wlh][2]];
                key = getkey(w,l,h);
                if(vg[key] == 0){
                    vg[key] = getg(cuboids,w,l,h);
                }
            }
        }
        initequal(cuboids,vequal);
        
        auto cmp= [](pair<int,pair<int,int>> &a,pair<int,pair<int,int>> & b){
            if(a.second.first + a.second.second == b.second.first + b.second.second){
                return a.first > b.first;
            }
            return a.second.first + a.second.second < b.second.first + b.second.second;
        };
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,decltype(cmp)> pq(cmp);
        pq.push({{getkey(100,100,100)},{0,INT_MAX}});
        vector<char> visit(MAX * MAX * MAX +  MAX * MAX  + MAX + 1,0);
        int ret = 0;
        pair<int,pair<int,int>> top;
        int value;
        while(!pq.empty()){
            top = pq.top();
            pq.pop();

            if(visit[top.first] == 1){continue;}
            if(ret >= top.second.first + top.second.second){break;}
            visit[top.first] = 1;
            
            if(top.second.second == 0){
                ret = max(ret,top.second.first);
                break;
            }
            key = top.first;
            w=key / MAX / MAX;l = (key/MAX)%MAX;h = key%MAX;
            value = top.second.first + vequal[key];
            bool flag = false;
            for(int i = 0; i < n; i ++){                
                for(int wlh = 0; wlh < nvindex; wlh ++){
                    ww = cuboids[i][vindex[wlh][0]];ll = cuboids[i][vindex[wlh][1]];hh = cuboids[i][vindex[wlh][2]];
                    if(ww==w && ll == l && hh == h){
                        break;
                    }
                    else if(ww<=w && ll <=l&& hh <= h){
                        kkey = getkey(ww,ll,hh);
                        if(visit[kkey] == 1){continue;}
                        
                        pq.push({{kkey},{value,vg[kkey]}});
                        flag = true;
                    }
                }
            }    
            if(flag == false) {
                ret = max(ret,value);
                break;
            }
        }
        return ret;
    }
};

// int main(){
//     vector<vector<int>> cuboids={
// {13,82,63},{86,27,31},{96,75,81},{6,77,53},{86,59,83},{68,76,7},{86,40,40},{72,20,13},{6,63,31},{69,87,40},{88,1,33},{88,89,60},{84,10,2},{90,61,38},{13,95,28},{5,24,48},{18,59,72},{65,80,78},{26,64,45},{16,45,29},{83,94,86},{21,98,7},{3,3,88},{60,45,52},{25,78,32},{48,65,65},{78,18,93},{71,61,24},{41,89,15},{44,26,70},{62,85,1},{12,63,41},{5,78,9},{65,75,22},{74,12,54},{84,14,47},{54,55,91},{43,69,46},{39,55,21},{31,80,28},{5,52,82},{70,79,38},{48,90,70},{35,23,62},{66,80,62},{6,85,35},{88,70,79},{62,49,37},{57,59,95},{28,50,96},{54,10,49},{38,56,25},{40,52,54},{7,65,76},{100,9,26},{68,77,83},{73,58,81},{86,60,72},{1,17,17},{90,74,5},{87,100,12},{74,63,48},{27,2,79},{38,30,49},{65,32,38},{30,83,11}
//     };
//     cuboids.clear();
//     for(int i = 0; i < 1000; i ++){
//         cuboids.push_back({rand() % 100,rand() % 100,rand() % 100});
//     }
//     Solution solution;
//     int ret = solution.maxHeight(cuboids);
//     return 0;
// }