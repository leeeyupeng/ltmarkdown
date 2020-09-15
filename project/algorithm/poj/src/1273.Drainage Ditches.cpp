#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

#include <cstdio>
#include <cstring>

using namespace std;

#define MMAX 200
#define CMAX 10000000
class Solution {
private:
	int n, m;
	int matric[MMAX +2][MMAX + 2];
	int matricf[MMAX + 2][MMAX + 2];
	int s, e;
	vector<int> path;
	vector<bool> visit;
	bool dfs(int i) {		
		path.push_back(i);
		visit[i] = true;
		if (i == e) { return true; }
		for (int j = 1; j <= m; j++) {
			if (visit[j]) { continue; }
			if (matric[i][j] - matricf[i][j] > 0 || matricf[j][i] != 0) {				
				if (dfs(j)) { return true; }				
			}
		}
		//visit[i] = false;
		path.pop_back();
		return false;
	}
	int FordFulkerson(int s, int e) {
		this->s = s;
		this->e = e;
		int flow = 0;
		int i, j;
		for (int i = 1; i <= m; i++) {
			visit[i] = false;
		}
		path.clear();

		while (dfs(this->s)) {
			int cp = CMAX;
			for (int k = 1; k < path.size(); k++) {
				i = path[k - 1];
				j = path[k];
				if (matric[i][j] - matricf[i][j] > 0) {
					cp = min(cp, matric[i][j] - matricf[i][j]);
				}
				else {
					cp = min(cp, matricf[j][i]);
				}
			}
			flow += cp;
			for (int k = 1; k < path.size(); k++) {
				i = path[k - 1];
				j = path[k];
				if (matric[i][j] - matricf[i][j] > 0) {
					matricf[i][j] += cp;
				}
				else {
					matricf[j][i] -= cp;
				}
			}

			for (int i = 1; i <= m; i++) {
				visit[i] = false;
			}
			path.clear();
		}
		return flow;
	}
public:
	void solve()
	{
		while (scanf("%d%d", &n, &m) != EOF) {
			for (int i = 1; i <= m; i++) {
				for (int j = 1; j <= m; j++) {
					matric[i][j] = 0;
					matricf[i][j] = 0;
				}
			}
			visit = vector<bool>(m + 1);
			for (int i = 1; i <= m; i++) {
				visit[i] = false;
			}

			int s, e, c;
			for (int i = 0; i < n; i++) {
				scanf("%d%d%d", &s, &e, &c);
				matric[s][e] += c;
			}

			int ans = FordFulkerson(1, m);
			printf("%d\n", ans);
		}
	}
};

//int main() {
//	Solution s;
//	s.solve();
//	return 0;
//}
