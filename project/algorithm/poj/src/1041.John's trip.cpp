#include <iostream>
#include <vector>
#include <queue>
#include <set>
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
					}
				}
			}
		}
	}

	unsigned short n, m;
	bool visit[1995];
	pair<unsigned short, unsigned short> edge[1995];
	vector<unsigned short> graph[45];
	vector<int> path;
	void add(unsigned short x, unsigned short y, unsigned short z) {
		n++;
		m = max(m, x);
		m = max(m, y);
		edge[z] = pair<unsigned short, unsigned short>(x,y);
		graph[x].push_back(z);
		graph[y].push_back(z);
	}
	// Hierholzer Ëã·¨
	void dfs(int node) {
		vector<unsigned short>& v = graph[node];
		for (int i = 0; i < v.size(); i++)
		{
			if (visit[v[i]]==false) {
				visit[v[i]] = true;
				dfs(edge[v[i]].first == node? edge[v[i]].second: edge[v[i]].first);
				path.push_back(v[i]);
			}
		}		
	}
public:
	void solve()
	{
		charzero = '0';
		charnine = '9';
		charenter = '\n';

		unsigned short x, y, z;
		unsigned short start;
		while (true) {
			x = 0, y = 0, z = 0;
			read(x);
			read(y);
			if (x == 0 && y == 0) { break; }
			start = min(x,y);
			n = 0; m = 0;
			memset(visit, 0, sizeof(bool) * 1995);
			for (int i = 1; i < 45; i++) {
				graph[i].clear();
			}
			path.clear();
			read(z);
			add(x,y,z);
			while (true) {
				x = 0, y = 0, z = 0;
				read(x);
				read(y);
				if (x == 0 && y == 0) { break; }
				read(z);
				add(x, y, z);
			}

			for (int i = 1; i <= m; i++) {
				sort(graph[i].begin(), graph[i].end());
			}

			bool exist = true;
			for (int i = 1; i <= m; i++) {
				if ((graph[i].size() & 0x1) == 0x1) {
					exist = false;
					break;
				}
			}
			if (exist == false) {
				printf("%s\n", "Round trip does not exist.");
				continue;
			}

			dfs(start);
			for (int i = path.size() - 1; i >= 0; i--) {
				printf("%d", path[i]);
				if (i != 0) { printf(" "); }
			}
			printf("\n");
		}
	}
};

//int main() {
//	Solution s;
//	s.solve();
//	return 0;
//}
