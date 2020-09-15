#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
private:
	int n, m;
	vector<vector<pair<int,bool>>> vq;
	vector<int> path;
	bool flag[10001];
	int edgecount;
	// Hierholzer Ëã·¨
	void dfs(int node) {
		if (flag[node] == false) {
			int front;
			vector<pair<int, bool>>& m = vq[node];
			for (int i = 0; i < m.size(); i++)
			{
				if (flag[node] == true || edgecount <= 0) { break; }
				if (m[i].second) {
					m[i].second = false;
					edgecount--;
					dfs(m[i].first);
				}
			}
		}
		flag[node] = true;
		path.push_back(node);
	}
public:
	void solve()
	{
		//cin >> n >> m;
		scanf("%d%d", &n,&m);
		vq = vector<vector<pair<int, bool>>>(n + 1);
		int start, end;
		for (int i = 0; i < m; i++) {
			//cin >> start >> end;
			scanf("%d%d", &start, &end);
			vq[start].push_back(pair<int, bool>(end,true));
			vq[end].push_back(pair<int, bool>( start,true ));
		}
		edgecount = m * 2;

		for (int i = 0; i <= n; i++)
		{
			flag[i] = false;
		}
		dfs(1);

		for (int i = path.size() - 1; i >= 0; i--) {
			//cout << path[i]<< endl;
			printf("%d\n", path[i]);
		}
	}
};

//int main() {
//	Solution s;
//	s.solve();
//	return 0;
//}
