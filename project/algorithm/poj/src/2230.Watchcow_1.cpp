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
	vector<stack<int>> vq;
	vector<int> path;
	// Hierholzer �㷨
	void dfs(int node) {
		int front;
		while (!vq[node].empty()) {
			front = vq[node].top();
			vq[node].pop();
			dfs(front);
		}
		path.push_back(node);
	}
public:
	void solve()
	{
		cin >> n >> m;
		vq = vector<stack<int>>(n + 1);
		int start, end;
		for (int i = 0; i < m; i++) {
			cin >> start >> end;
			vq[start].push(end);
			vq[end].push(start);
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
