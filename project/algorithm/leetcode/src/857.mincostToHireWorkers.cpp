#include"leetcode.h"

#define MAX 10010
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        priority_queue<int,vector<int>,std::function<bool(const int a,const int b)>> q([&quality,&wage](const int a,const int b){
            if(wage[a] * quality[b] == wage[b]*quality[a]){
                return quality[a]<quality[b];
            }
            return wage[a] * quality[b] < wage[b]*quality[a];
        });
        int n = quality.size();
        for(int i = 0; i < n; i++){
            q.push(i);
        }

        vector<int> vcounter(MAX);
        for(int i = 0; i < MAX; i ++){
            vcounter[i] = 0;
        }
        for(int i = 0; i < n; i ++){
            vcounter[quality[i]]++;
        }
        double costmax = 0;
        int qualitynums = 0;
        for(int i = 1; i < MAX; i ++){
            qualitynums+=vcounter[i] * i;
        }
        int index = q.top();
        costmax = ((double)qualitynums * wage[index]) / quality[index];
        double ans = costmax;
                    
        qualitynums = 0;
        int kk = 0;
        int counterindex=MAX;
        for(int i = 1; i < MAX; i ++){
            if(kk + vcounter[i] <= K){
                qualitynums += vcounter[i] * i;
                kk += vcounter[i];
                vcounter[i] = 0;
            }
            else{
                qualitynums+=i * (K - kk);
                vcounter[i] -= K-kk;
                kk = K;
                counterindex = i;
                break;
            }
        }
        while(!q.empty() && q.size()>=K){
            int index = q.top();
            ans = min(ans,((double)qualitynums * wage[index]) / quality[index]);
            if(q.size() == K){break;}
            q.pop();            
            if(vcounter[quality[index]]>0){vcounter[quality[index]]--;}
            else{
                while(counterindex<MAX && vcounter[counterindex]==0){counterindex++;}
                qualitynums += counterindex - quality[index];
                vcounter[counterindex] --;
            }
        }
        return ans;
    }
};

// int main(){
//     Solution solution;
//     vector<int> quality={
// 3,4,3
//     };
//     vector<int> wage={
// 13,8,20
//     };
//     int K = 1;
//     double ans = solution.mincostToHireWorkers(quality,wage,K);
//     return 0;
// }