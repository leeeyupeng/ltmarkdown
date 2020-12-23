#include <iostream>
#include <stdio.h>
#include <string.h>
 
const int MAXN = 1005;
int mp[MAXN][MAXN],ans[MAXN];
 
void Hamilton(int ans[MAXN], int mp[MAXN][MAXN], int n, int st) {
    int nxt[MAXN];
    memset(nxt, -1, sizeof(nxt));
    int head = st;
    for(int i = 1; i <= n; i++) {
        if(i == st)continue;
        if(mp[i][head]) {
            nxt[i] = head;
            head = i;
        }else {
            int pre = head, pos = nxt[head];
            while(pos != -1 && !mp[i][pos]) {
                pre = pos;
                pos = nxt[pre];
            }
            nxt[pre] = i;
            nxt[i] = pos;
        }
    }
    int cnt = 0;
    for(int i = head; i != -1; i = nxt[i]) ans[++cnt] = i;
}
// int main(void)
// {
//     int n;
//     while(scanf("%d",&n) != EOF && n) {
//         for(int i = 1; i <= n; i++) {
//             for(int j = 1; j <= n; j++) {
//                 //scanf("%d",&mp[i][j]);
//                 int r = rand() % 2;
//                 mp[i][j] = r;
//                 mp[j][i] = r==1?0:1;
//             }
//         }
//         if(n == 1){ printf("1\n");continue; }
//         int flag = 0;
//         for(int i = 1; i <= n; i++) {
//             Hamilton(ans, mp, n,i);
//             if(mp[ans[n]][ans[1]]) {
//                 flag = 1;
//                 for(int k = 1; k <= n; k++) {
//                     if(k == 1) printf("%d",ans[k]);
//                     else printf(" %d",ans[k]);
//                 }
//                 printf("\n");
//                 break;
//             }
//         }
//         if(!flag) printf("-1\n");
//     }
//     return 0;
// }
