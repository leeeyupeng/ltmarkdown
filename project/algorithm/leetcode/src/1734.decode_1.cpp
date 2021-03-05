#include"leetcode.h"

#define BIT 17
class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int en = encoded.size();
        int n = en + 1;
        vector<int> bitnums(BIT,0);

        int temp = 0;
        int bit = 0;
        for(int i = 1; i <= n; i ++){
            temp = i;
            bit = 0;
            while(temp != 0){
                bitnums[bit] += temp & 0x1;
                temp >>=1;
                bit ++;
            }
        }

        int x0 = 0;
        int bitnum = 0;
        for(int ibit = 0; ibit < BIT; ibit ++){
            bit = 0;  
            bitnum = 0;        
            for(int i = 0; i < en; i ++){
                bit = bit ^ ((encoded[i] >> ibit) & 0x1);          
                bitnum +=bit;
            }
            //条件中没有  奇数限制 会有问题 
            //bitnum == bitnums[ibit]
            //bitnum + bitnums[ibit] == n
            //可能这两个条件都满足，此为就有可能为0，或者1，无法确定
            if(bitnum == bitnums[ibit]){

            }
            else if(bitnum + bitnums[ibit] == n){
                x0 += 1 <<ibit;
            }
            else{
                //无法解密
                cout<<"error"<<endl;
            }
        }
        vector<int> ret(n,0);
        temp = x0;
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