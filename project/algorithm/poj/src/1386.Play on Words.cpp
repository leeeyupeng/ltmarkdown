#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

#include <cstdio>
#include <cstring>

using namespace std;

class Solution {
private:
	char charzero;
	char charnine;
	char charenter;
	char ch;
	inline void read(unsigned int& x) {
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

	inline void readline(char& s, char& e) {
		ch = getchar();
		s = ch;
		while ('a' <= ch && ch <= 'z') {
			e = ch;
			ch = getchar();
		}
	}
	char unionset[26];
	char rank[26];
	bool visit[26];
	//inline void Union(char s, char e) {
	//	char cs = Find(s);
	//	char ce = Find(e);
	//	unionset[ce] = cs;
	//	//if (rank[cs] < rank[ce]) {
	//	//	unionset[ce] = cs;
	//	//}
	//	//else if(rank[cs] > rank[ce]) {
	//	//	unionset[cs] = ce;
	//	//}
	//	//else {
	//	//	unionset[cs] = ce;
	//	//	rank[ce] += 1;
	//	//}
	//}
	char cs;
	char cc;
	inline void Union(char s, char e) {
		cs = unionset[s];
		if (unionset[e] != cs) {
			cc = unionset[e];
			unionset[e] = cs;
			e = cc;
			if (unionset[e] != cs) {
				cc = unionset[e];
				unionset[e] = cs;
				e = cc;
				if (unionset[e] != cs) {
					cc = unionset[e];
					unionset[e] = cs;
					e = cc;
					if (unionset[e] != cs) {
						cc = unionset[e];
						unionset[e] = cs;
						e = cc;
					}
				}
			}
		}

		if (unionset[s] != cs) {
			cc = unionset[s];
			unionset[s] = cs;
			s = cc;
			if (unionset[s] != cs) {
				cc = unionset[s];
				unionset[s] = cs;
				s = cc;
				if (unionset[s] != cs) {
					cc = unionset[s];
					unionset[s] = cs;
					s = cc;
					if (unionset[s] != cs) {
						cc = unionset[s];
						unionset[s] = cs;
						s = cc;
						if (unionset[s] != cs) {
							cc = unionset[s];
							unionset[s] = cs;
							s = cc;
						}
					}
				}
			}
		}
	}
	//inline char Find(char c) {
	//	while (unionset[c] != c) {
	//		unionset[c] = unionset[unionset[c]];
	//		c = unionset[c];					
	//	}
	//	return c;
	//}
	//inline char Find(char c) {
	//	if (unionset[c] != c) {
	//		unionset[c] = Find(unionset[c]);				
	//	}
	//	return unionset[c];
	//}
	char s[26];
	char top;
	inline char Find(char c) {
		if (unionset[unionset[c]] == unionset[c]) {
			return unionset[c];
		}
		top = 0;
		while (unionset[c] != c) {
			s[top++] = c;
			c = unionset[c];
		}
		while (top > 0) {
			unionset[s[--top]] = c;
		}
		return c;
	}
	bool IsOneUnion() {
		char one = 0;
		for (int i = 0; i < 26; i++) {
			if (unionset[i] == i && visit[i]) { one++; }
		}
		return one == 1;
	}
	unsigned int degree[26];
	bool isdegree() {
		unsigned int zero = 0;
		unsigned int fuone = 0;
		unsigned int zhengone = 0;
		for (int i = 0; i < 26; i++) {
			if (degree[i] == 0) { zero++; }
			else if(degree[i] == -1) { fuone++; }
			else if (degree[i] == 1) { zhengone++; }
			else { return false; }
		}
		if (fuone == 0 && zhengone == 0) { return true; }
		if (fuone == 1 && zhengone == 1) { return true; }
		return false;
	}
public:
	void solve()
	{
		charzero = '0';
		charnine = '9';
		charenter = '\n';

		unsigned int test=0;
		read(test);
		unsigned int n = 0;
		unsigned int count;
		char s, e;
		while (test-- > 0) {
			n = 0;
			read(n);
			count = n;
			memset(visit, 0, sizeof(bool) * 26);
			memset(unionset, 0, sizeof(char) * 26);
			memset(rank, 1, sizeof(char) * 26);
			memset(degree, 0, sizeof(unsigned int) * 26);
			for (char i = 0; i < 26; i++) {
				unionset[i] = i;
			}
			while (count-- > 0) {
				readline(s,e);
				s -= 'a';
				e -= 'a';
				degree[s]--;
				degree[e]++;
				visit[s] = true;
				visit[e] = true;
				Union(s,e);
			}
			if (!IsOneUnion()) {
				printf("%s\n", "The door cannot be opened.");
				continue;
			}
			if (isdegree()) {
				printf("%s\n", "Ordering is possible.");
			}
			else {
				printf("%s\n", "The door cannot be opened.");
			}
		}
	}
};

//int main() {
//	Solution s;
//	s.solve();
//	return 0;
//}
