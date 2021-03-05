#include"leetcode.h"

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int en = encoded.size();
        int n = en + 1;
        vector<int> visit(n+1,0);
        vector<int> ret(n,0);
        int temp = 0;
        int i,j;
        for(i = 1; i <= n; i ++){
            ret[0] = i;
            visit[i] = i;
            temp = i;
            for(j = 0; j < en; j ++){
                temp = temp ^ encoded[j];                
                if(temp < 1 || temp > n ||  visit[temp] == i){
                    break;
                }
                else{
                    ret[j+1] = temp;
                    visit[temp] = i;
                }
            }
            if(j == en){break;}
        }
        return ret;
    }
};

// int main(){
//     vector<int> encoded;
//     int n;
//     int temp;
//     while(cin>>n){
//         temp = n;
//         for(int i = 1; i <= n-1; i ++){
//             encoded.push_back(temp ^ i);
//             temp = i;
//         }

//         Solution solution;
//         vector<int> ret = solution.decode(encoded);
//         return 0;
//     }
// }