#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
	struct edge {
		edge* next;
		int end;
		edge(int _end) :end(_end), next(NULL) {}
	};
private:
	int n, m;
	vector<edge*> vq;
	vector<int> path;
	// Hierholzer Ëã·¨
	void dfs(int node) {
		int front;
		while (vq[node]!= NULL) {
			front = vq[node]->end;
			vq[node] = vq[node]->next;
			dfs(front);
		}
		path.push_back(node);
	}
public:
	void solve()
	{
		cin >> n >> m;
		vq = vector<edge*>(n + 1);
		int start, end;
		for (int i = 0; i < m; i++) {
			cin >> start >> end;
			edge* e = new edge(end);
			e->next = vq[start];
			vq[start] = e;

			e = new edge(start);
			e->next = vq[end];
			vq[end] = e;
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
