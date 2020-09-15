#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

#include <cstdio>
#include <cstring>

using namespace std;

#define MMAX 1000
#define CMAX 10000000
class Solution {
private:
	struct edge {
		int index;
		int a;
		int length;
		int c;
		edge* next;
		edge(int _index,int _a, int _length) :index(_index),a(_a), length(_length), c(1),next(NULL) {}
	};

	int n, m;
	edge* edges[20100];
	edge* v[MMAX + 2];
	int s, e;
	vector<int> path;
	vector<bool> visit;
	bool spfa(int s, int e) {
		vector<int> preedge = vector<int>(n + 2);
		vector<int> prev = vector<int>(n + 2);
		for (int i = 0; i < n + 2; i++) {
			preedge[i] = -1;
			prev[i] = i;
		}
		vector<int> vlength(n+2);
		for (int i = 0; i < n + 2; i++) {
			vlength[i] = -1;
		}
		vlength[0] = 0;
		path.clear();
		queue<int> q;
		q.push(s);
		int i;

		while (!q.empty()) {
			i = q.front();
			q.pop();
			edge* es = v[i];
			while (es != NULL) {
				if (es->c > 0) {
					if (vlength[es->a] == -1 || vlength[es->a] > vlength[i] + es->length) {
						q.push(es->a);
						vlength[es->a] = vlength[i] + es->length;
						preedge[es->a] = es->index;
						prev[es->a] = i;
					}
				}
				es = es->next;
			}
		}
		if (prev[e]!=e) {
			int p = e;
			while (prev[p] != p) {
				path.push_back(preedge[p]);
				p = prev[p];				
			}
			reverse(path.begin(), path.end());
		}
		return prev[e] != e;
	}
	int FordFulkerson(int s, int e) {
		this->s = s;
		this->e = e;
		int cost = 0;
		int i, j;
		while (spfa(this->s, this->e)) {
			int cp = 1;
			int cpcost = 0;
			for (int k = 0; k < path.size(); k++) {
				cpcost += edges[path[k]]->length;
			}
			cost += cp * cpcost;
			for (int k = 1; k < path.size(); k++) {
				edges[path[k]]->c--;

				if (path[k] != (m << 1) && path[k] != (m << 1) + 1) {
					if ((path[k] & 0x1) == 0x0) {
						edges[path[k] + 1]->length = -edges[path[k] + 1]->length;
					}
					else
					{
						edges[path[k] - 1]->length = -edges[path[k] - 1]->length;
					}
				}
			}
		}
		return cost;
	}
public:
	void solve()
	{
		{
			scanf("%d%d", &n, &m);
			for (int i = 0; i < n + 2; i++) {
				v[i] = NULL;
			}
			int s, e, length;
			for (int i = 0; i < m; i++) {
				scanf("%d%d%d", &s, &e, &length);
				edges[i << 1] = new edge(i << 1, e, length);
				edges[(i << 1) + 1] = new edge((i << 1) + 1, s, length);

				edges[i << 1]->next = v[s];
				v[s] = edges[i << 1];

				edges[(i << 1) + 1]->next = v[e];
				v[e] = edges[(i << 1) + 1];
			}
			edges[m << 1] = new edge(m << 1, 1, 0);
			edges[(m << 1) + 1] = new edge((m << 1) + 1, n + 1, 0);
			edges[m << 1]->c = 2;
			edges[m << 1]->next = v[0];
			v[0] = edges[m << 1];

			edges[(m << 1) + 1]->c = 2;
			edges[(m << 1) + 1]->next = v[n];
			v[n] = edges[(m << 1) + 1];

			int ans = FordFulkerson(0, n + 1);
			printf("%d\n", ans);

		}
	}
};

//int main() {
//	Solution s;
//	s.solve();
//	return 0;
//}
