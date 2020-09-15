#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include<string>
#include<algorithm>
using namespace std;

#define N 50
#define M 50
class Solution {
private:
	int n, m;
	vector<vector<char>> maze;
	vector<vector<int>> vG;
	vector<vector<int>> vB;
	bool SolveB()
	{
		int temp;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (maze[i][j] == 'B') {
					if (i > 0) {
						temp = i - 1;
						if (maze[temp][j] == '.') { maze[temp][j] = '#'; }
						else if (maze[temp][j] == 'G') { return false; }
					}
					if (i < n - 1) {
						temp = i + 1;
						if (maze[temp][j] == '.') { maze[temp][j] = '#'; }
						else if (maze[temp][j] == 'G') { return false; }
					}
					if (j > 0) {
						temp = j - 1;
						if (maze[i][temp] == '.') { maze[i][temp] = '#'; }
						else if (maze[i][temp] == 'G') { return false; }
					}
					if (j < m - 1) {
						temp = j + 1;
						if (maze[i][temp] == '.') { maze[i][temp] = '#'; }
						else if (maze[i][temp] == 'G') { return false; }
					}
				}
			}
		}
		return true;
	}

	void DFS(int i, int j) {
		if (maze[i][j] == 'T') { return; }
		maze[i][j] = 'T';

		if (i > 0 && maze[i - 1][j] != '#') { DFS(i - 1, j); }
		if (i < n - 1 && maze[i + 1][j] != '#') {DFS(i + 1, j); }
		if (j > 0 && maze[i][j - 1] != '#') { DFS(i, j - 1); }
		if (j < m - 1 && maze[i][j + 1] != '#') { DFS(i, j + 1); }
	}
	bool Solve() {
		if (SolveB() == false) { return false; }
		vG.clear();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (maze[i][j] == 'G') { vG.push_back({ i,j }); }
			}
		}

		if (maze[n - 1][m - 1] != '#') { DFS(n - 1, m - 1); }
		for (int i = 0; i < vG.size(); i++) {
			if (maze[vG[i][0]][vG[i][1]] == 'G') {
				return false;
			}
		}
		return true;
	}
public:
	void Cases()
	{
		int t;
		cin >> t;
		maze = vector<vector<char>>(N, vector<char>(M, '.'));
		for (int it = 0; it < t; it++) {
			cin >> n >> m;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cin >> maze[i][j];
				}
			}
			bool ans = Solve();
			cout << (ans ? "Yes" : "No") << endl;
		}
	}
};
int main()
{
	Solution s;
	s.Cases();
	return 0;
}