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
	// Hierholzer �㷨
	//void dfs(int node) {
	//	int front;
	//	vector<pair<int, bool>>& m = vq[node];
	//	for(int i = 0; i < m.size(); i ++)
	//	{
	//		if (m[i].second) {
	//			m[i].second = false;
	//			dfs(m[i].first);
	//		}
	//	}
	//	path.push_back(node);
	//}
	void dfs(int node) {
		stack<int> s;
		s.push(node);
		int top;
		int i;
		bool flag;
		while (!s.empty()) {
			top = s.top();	
			vector<pair<int, bool>>& m = vq[top];
			flag = false;
			for (i = 0; i < m.size(); i++)
			{
				if (m[i].second) {
					m[i].second = false;
					s.push(m[i].first);
					flag = true;
					break;
				}
			}
			if (flag == false) {
				s.pop();
				path.push_back(top);
			}
		}
	}
public:
	void solve()
	{
		//cin >> n >> m;
		scanf("%d%d", &n, &m);
		vq = vector<vector<pair<int, bool>>>(n + 1);
		int start, end;
		for (int i = 0; i < m; i++) {
			//cin >> start >> end;
			scanf("%d%d", &start, &end);
			vq[start].push_back(pair<int, bool>(end,true));
			vq[end].push_back(pair<int, bool>( start,true ));
		}

		dfs(1);

		for (int i = path.size() - 1; i >= 0; i--) {
			//cout << path[i]<< endl;
			printf("%d\n", path[i]);
		}
	}
};
//
//int main() {
//	Solution s;
//	s.solve();
//	return 0;
//}
