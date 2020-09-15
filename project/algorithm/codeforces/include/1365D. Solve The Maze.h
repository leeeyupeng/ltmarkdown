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
	vector<vector<bool>> visit;
	void SolveB()
	{
		int temp;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (maze[i][j] == 'B') {
					if (i > 0) {
						temp = i - 1;
						if (maze[temp][j] == '.') { maze[temp][j] = '#'; }
					}
					if (i < n - 1) {
						temp = i + 1;
						if (maze[temp][j] == '.') { maze[temp][j] = '#'; }
					}
					if (j > 0) {
						temp = j - 1;
						if (maze[i][temp] == '.') { maze[i][temp] = '#'; }
					}
					if (j < m - 1) {
						temp = j + 1;
						if (maze[i][temp] == '.') { maze[i][temp] = '#'; }
					}
				}
			}
		}
	}
	void DFS(int i, int j) {
		if (visit[i][j] == true) { return; }
		visit[i][j] =true;
		
		bool flag = false;
		if (i > 0 && maze[i - 1][j] != '#') { DFS(i - 1, j); }
		if (i < n-1 && maze[i + 1][j] != '#') { DFS(i + 1, j); }
		if (j > 0 && maze[i][j-1] != '#') { DFS(i, j-1); }
		if (j < m - 1 && maze[i][j+1] != '#') { DFS(i, j+1); }
		
	}
	bool Solve() {
		SolveB();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				visit[i][j] = false;
			}
		}
		if (maze[n - 1][m - 1] != '#') {
			DFS(n - 1, m - 1);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (maze[i][j] == 'G' && visit[i][j] == false) { return false; }
				if (maze[i][j] == 'B' && visit[i][j] == true) { return false; }
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
		visit = vector<vector<bool>>(N, vector<bool>(M, false));
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
int maincodeforces()
{
	Solution s;
	s.Cases();
	return 0;
}