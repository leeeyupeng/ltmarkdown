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
        int idx=0;
        for(int i = 0; i < n; i ++){
            if((row[i<<1]&0x1) == 0x0){
                if(row[(i<<1) + 1] == row[i<<1] + 1){
                    continue;
                }
                else{
                    idx = index[row[i<<1] + 1];
                    swap(row[(i<<1) + 1],row[idx]);
                    index[row[i<<1] + 1] = (i<<1) + 1;
                    index[row[idx]] = idx;
                    ret ++;
                }
            }
            else{
                if(row[(i<<1) + 1] == row[i<<1] - 1){
                    continue;
                }
                else{
                    idx = index[row[i<<1] - 1];
                    swap(row[(i<<1) + 1],row[idx]);
                    index[row[i<<1] - 1] = (i<<1) + 1;
                    index[row[idx]] = idx;
                    ret ++;
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