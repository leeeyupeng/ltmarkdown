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
	// Hierholzer Ëã·¨
	void dfs(int node) {
		int front;
		vector<pair<int, bool>>& m = vq[node];
		for(int i = 0; i < m.size(); i ++)
		{
			if (m[i].second) {
				m[i].second = false;
				dfs(m[i].first);
			}
		}
		path.push_back(node);
	}
public:
	void solve()
	{
		cin >> n >> m;
		vq = vector<vector<pair<int, bool>>>(n + 1);
		int start, end;
		for (int i = 0; i < m; i++) {
			cin >> start >> end;
			vq[start].push_back(pair<int, bool>(end,true));
			vq[end].push_back(pair<int, bool>( start,true ));
		}

		dfs(1);

		for (int i = path.size() - 1; i >= 0; i--) {
			cout << path[i]<< endl;
		}
	}
};

//int main() {
//	Solution s;
//	s.solve();
//	return 0;
//}
