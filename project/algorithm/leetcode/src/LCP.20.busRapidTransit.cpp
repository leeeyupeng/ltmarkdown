#include"leetcode.h"

class Solution {
private:
    int target;
    int inc;
    int dec;
    vector<int> jump;
    vector<int> cost;
    int jumpnums;
    unordered_map<int,long long> m;
    long long dfs(int target){
        if(m.find(target) != m.end()){return m[target];}
        long long ans = 1ll * target * inc;
        int div = 0;
        for(int i = 0; i < jumpnums;i++){
            div = target / jump[i];
            ans = min(ans,dfs(div) + cost[i] + (target - 1ll*div * jump[i])*inc);
            if(div+1<target){
                ans = min(ans,dfs(div+1) + cost[i] + (1ll*(div+1) * jump[i] - target) * dec);
            }
        }
        m[target] = ans;
        return ans;
    }
public:
    int busRapidTransit(int target, int inc, int dec, vector<int>& jump, vector<int>& cost) {
        this->target = target;
        this->inc = inc;
        this->dec = dec;
        this->jump = jump;
        this->cost = cost;
        this->jumpnums = jump.size();
        m[0] = 0;
        m[1] = inc;
        return dfs(target) % 1000000007ll;
    }
};