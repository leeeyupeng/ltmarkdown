#include"leetcode.h"

class Solution {
private:
    int usfind(vector<int>& us,int index){
        if(us[index] != index){
            us[index] = usfind(us,us[index]);
        }
        return us[index];
    }
public:
    int minSwapsCouples(vector<int>& row) {
        int n2 = row.size();
        int n = row.size()>>1;
        vector<int> index(n2,0);
        for(int i = 0; i < n2; i ++){
            index[row[i]] = i;
        }
        int ret = 0;

        vector<int> us(n,0);
        for(int i = 0; i < n; i ++){us[i] = i;}
        int a,b;
        for(int i = 0; i < n; i ++){
            a = usfind(us,row[(i<<1)]>>1);
            b = usfind(us,row[(i<<1) + 1]>>1);
            if(a!=b){
                us[b] = a;
            }
        }
        vector<int> counter(n,0);
        for(int i = 0; i < n; i ++){
            counter[usfind(us,i)]++;
        }
        for(int i = 0; i < n; i ++){
            if(counter[i] != 0){
                ret += counter[i] - 1;
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