#include"leetcode.h"

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n2 = row.size();
        int n = row.size()>>1;
        vector<int> index(n2,0);
        for(int i = 0; i < n2; i ++){
            index[row[i]] = i;
        }
        int ret = 0;
        vector<char> visit(n,0);
        queue<int> q;
        int front;
        int idx=0;
        for(int i = 0; i < n; i ++){
            if(visit[i] == 0){
                visit[i] = 1;
                q.push(i);
                while(!q.empty()){
                    front = q.front();
                    q.pop();
                    idx = index[(front<<1)];
                    if((idx&0x1) == 0x0){
                        idx ++;
                    }
                    else{
                        idx--;
                    }
                    if(visit[row[idx]>>1] == 0){
                        visit[row[idx]>>1] = 1;
                        q.push(row[idx]>>1);
                        ret++;
                    }

                    idx = index[(front<<1) + 1];
                    if((idx&0x1) == 0x0){
                        idx ++;
                    }
                    else{
                        idx--;
                    }
                    if(visit[row[idx]>>1] == 0){
                        visit[row[idx]>>1] = 1;
                        q.push(row[idx]>>1);
                        ret++;
                    }

                }
            }
        }
        return ret;
    }
};

// int main(){
//     Solution solution;
//     vector<int> row={
//         2,0,1,3
//     };

//     auto ret = solution.minSwapsCouples(row);
//     return 0;
// }