#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include<limits.h>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAX 50010
int nums[MAX];
int log[MAX];
int stmax[MAX][20];
int stmin[MAX][20];
int read() {
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {  // ch 不是数字时
    if (ch == '-') w = -1;        // 判断是否为负
    ch = getchar();               // 继续读入
  }
  while (ch >= '0' && ch <= '9') {  // ch 是数字时
    x = x * 10 + (ch - '0');  // 将新读入的数字’加’在 x 的后面
    // x 是 int 类型，char 类型的 ch 和 ’0’ 会被自动转为其对应的
    // ASCII 码，相当于将 ch 转化为对应数字
    // 此处也可以使用 (x<<3)+(x<<1) 的写法来代替 x*10
    ch = getchar();  // 继续读入
  }
  return x * w;  // 数字 * 正负号 = 实际数值
}
inline void write(int x) {
  static int sta[35];
  int top = 0;
  do {
    sta[top++] = x % 10, x /= 10;
  } while (x);
  while (top) putchar(sta[--top] + 48);  // 48 是 '0'
}
class Solution {
public:
    void Solve(int n) {
        log[1] = 0;log[2] = 1;
        for(int i = 3; i <= n; i ++){
            log[i] = log[i>>1] + 1;
        }
        for(int i = 0; i < n; i ++){
            stmax[i][0] = nums[i];
        }
        for(int j = 1; j <= log[n];j ++){
            for(int i = 0; i+(1<<j) -1 < n; i ++){            
                stmax[i][j] = max(stmax[i][j-1],stmax[i + (1<<(j-1))][j-1]);
            }
        }
        for(int i = 0; i < n; i ++){
            stmin[i][0] = nums[i];
        }
        for(int j = 1; j <= log[n];j ++){
            for(int i = 0; i+(1<<j) -1 < n; i ++){            
                stmin[i][j] = min(stmin[i][j-1],stmin[i + (1<<(j-1))][j-1]);
            }
        }
    }

    inline int getminmax(int l,int r){
        int ans;        
        int s = log[r-l+1];
        ans = max(stmax[l][s],stmax[r - (1<<s) + 1][s]) - min(stmin[l][s],stmin[r - (1<<s) + 1][s]);
        return ans;
    }
};

int main(){
    int n,q;
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
    n = read();
    q = read();
    {
        for(int i = 0; i < n; i ++){
            nums[i] = read();
        }
        Solution solution;
        solution.Solve(n);
        int l,r;
        for(int i = 0; i < q; i ++){
            l = read();r = read();
            write(solution.getminmax(l-1,r-1));
            putchar('\n');
        }
        
    }
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif
    return 0;
}