#include"leetcode.h"

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int en = encoded.size();
        int n = en + 1;

        int oddsum = 0;
        for(int i = 1;i < en; i ++,i++){
            oddsum^=encoded[i];
        }
        int nsum = 0;
        for(int i = 1;i <= n; i ++){
            nsum^=i;
        }

        int x0 = oddsum ^ nsum;
        vector<int> ret(n,0);
        int temp = x0;
        ret[0] = x0;
        for(int j = 0; j < en; j ++){
            temp = temp ^ encoded[j];
            ret[j+1] = temp;
        }

        return ret;
    }
};

// int main(){
    
//     int n;
//     int temp;
//     while(cin>>n){
//         vector<int> decode(n,0);
//         for(int i = 0; i < n; i ++){
//             decode[i] = i + 1;
//         }
//         for(int i = 0; i < n; i ++){
//             swap(decode[rand()%n],decode[rand()%n]);
//         }
//         vector<int> encoded(n-1,0);
//         for(int i = 1; i < n; i ++){
//             encoded[i-1] = decode[i-1] ^ decode[i];
//         }

//         Solution solution;
//         vector<int> ret = solution.decode(encoded);

//         bool flag = true;
//         for(int i = 0; i < n; i ++){
//             flag &= decode[i] == ret[i];
//         }

//         return 0;
//     }
// }