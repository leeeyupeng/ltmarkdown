#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 10010, M = 100010;
unsigned short n, m;
unsigned int top, tot, cnt;
unsigned int head[N];
unsigned short ver[M];
unsigned int Next[M];
unsigned short s[M];	//模拟栈
unsigned short ans[M];	//答案栈
bool vis[M];

char charzero = '0';
char charnine = '9';
char charenter = '\n';

inline void add(unsigned short  x, unsigned short  y)
{
	ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
}

void euler()
{
	s[++top] = 1;
	while (top > 0)
	{
		unsigned short x = s[top];
		unsigned int i = head[x];
		//while(i && vis[i])	i = Next[i];	//找到一条尚未访问过的边
		if (i)
		{
			s[++top] = ver[i];
			//vis[i] = vis[i ^ 1] = true;
			head[x] = Next[i];
		}
		else {			//x连接的所有边都已经访问过了，回溯，级在答案栈中
			top--;
			ans[++cnt] = x;
		}
	}
}
char ch;
inline void read(unsigned short& x) {
	ch = getchar();
	if (charzero <= ch && ch <= charnine) {
		x = x * 10 + ch - charzero;
		ch = getchar();
		if (charzero <= ch && ch <= charnine) {
			x = x * 10 + ch - charzero;
			ch = getchar();
			if (charzero <= ch && ch <= charnine) {
				x = x * 10 + ch - charzero;
				ch = getchar();
				if (charzero <= ch && ch <= charnine) {
					x = x * 10 + ch - charzero;
					ch = getchar();
					if (charzero <= ch && ch <= charnine) {
						x = x * 10 + ch - charzero;
						ch = getchar();
						if (charzero <= ch && ch <= charnine) {
							x = x * 10 + ch - charzero;
							ch = getchar();
						}
					}
				}
			}
		}
	} 
}

char charout[5];
inline void out(unsigned short x) {
	char index = 0;
	if (x != 0) {
		charout[index++] = x % 10;
		x /= 10;
	}
	if (x != 0) {
		charout[index++] = x % 10;
		x /= 10;
	}
	if (x != 0) {
		charout[index++] = x % 10;
		x /= 10;
	}
	if (x != 0) {
		charout[index++] = x % 10;
		x /= 10;
	}
	if (x != 0) {
		charout[index++] = x % 10;
		x /= 10;
	}
	if(index>0){
		putchar(charout[--index] + charzero);
	}
	if (index > 0) {
		putchar(charout[--index] + charzero);
	}
	if (index > 0) {
		putchar(charout[--index] + charzero);
	}
	if (index > 0) {
		putchar(charout[--index] + charzero);
	}
	if (index > 0) {
		putchar(charout[--index] + charzero);
	}
}

//int main()
//{
//	n = 0;
//	read(n);
//	m = 0;
//	read(m);
//	tot = 1;
//	unsigned short x, y;
//	for (unsigned short i = 0; i < m; ++i)
//	{
//		x = 0;
//		read(x);
//		y = 0;
//		read(y);
//		add(x, y);
//		add(y, x);
//	}
//	euler();
//	for (unsigned int i = cnt; i; --i)
//	{
//		out(ans[i]);
//		putchar(charenter);
//		//printf("%d\n", ans[i]);
//	}
//	return 0;
//}