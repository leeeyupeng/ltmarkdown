#include"leetcode.h"

#define MAX 10010
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        int n = quality.size();
        vector<int> vsort(n);
        for(int i = 0; i < n; i ++){
            vsort[i] = i;
        }
        sort(vsort.begin(),vsort.end(),[&quality,&wage](const int a,const int b){
            if(wage[a] * quality[b] == wage[b]*quality[a]){
                return quality[a]<quality[b];
            }
            return wage[a] * quality[b] < wage[b]*quality[a];
        });

        priority_queue<int> pq;
        double ans = ((double)wage[vsort[n-1]] * n * 10000) / quality[vsort[n-1]];
        int qualitynums = 0;
        for(int i = 0; i < n; i ++){
            if(pq.size() < K-1){
                pq.push(quality[vsort[i]]);
                qualitynums += quality[vsort[i]];
            }
            else if(pq.size() == K-1){
                pq.push(quality[vsort[i]]);
                qualitynums += quality[vsort[i]];
                ans = min(ans,((double)qualitynums * wage[vsort[i]])/quality[vsort[i]]);
            }
            else if(pq.size() == K){
                if(pq.top() > quality[vsort[i]]){
                    qualitynums-=pq.top();
                    qualitynums+=quality[vsort[i]];
                    pq.pop();
                    pq.push(quality[vsort[i]]);
                    ans = min(ans,((double)qualitynums * wage[vsort[i]])/quality[vsort[i]]);
                }
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