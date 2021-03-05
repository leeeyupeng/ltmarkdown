#include"hdu.h"

#define MAXN 5000010
int a[MAXN];
int b[MAXN];
constexpr int threshold = 10000000;
unsigned long long k1,k2;
unsigned long long xorShitf128Plus(){
    unsigned long long k3 = k1,k4 = k2;
    k1 = k4;
    k3^=(k3<<23);
    k2 = k3^k4^(k3>>17)^(k4>>26);
    return k2 + k4;
}
void gen(int n,unsigned long long _k1,unsigned long long _k2){
    k1 = _k1,k2 = _k2;
    for(int i = 0; i < n; i ++){
        a[i] = xorShitf128Plus() % threshold + 1;
        b[i] = xorShitf128Plus() % threshold + 1;
    }
}
// int main(){
//     ios::sync_with_stdio(0);
//     int n,m;
//     unsigned long long k1,k2;
//     while(scanf("%d%d%llu%llu",&n,&m,&k1,&k2)!=EOF){
//         gen(n,k1,k2);
        
//         a[n] = 0;
//         b[n] = 0;
//         for(int i = 0; i < n; i ++){
//             b[i] += a[i];
//         }
//         sort(a,a+n,greater<int>());
//         sort(b,b+n,greater<int>());

//         int cnt = 0;
//         int i = 0,j = 0;
        
//         long long ans = 0;
//         long long ret = 0;
//         while(cnt < m){
//             if(i == 0){
//                 ans += a[i++];                
//             }
//             else{
//                 if(a[i] > b[j] - a[i-1]){
//                     ans += a[i++];
//                 }
//                 else{
//                     ans += b[j] - a[i-1];
//                     j ++;i--;
//                 }
//             }
//             cnt++;
//             ret ^= ans;
//         }
//         printf("%lld\n",ret);
//     }
//     return 0;
// }