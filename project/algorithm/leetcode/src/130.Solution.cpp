#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class Solution {
private:
	struct Grid {
		int x;
		int y;

		Grid(int _x, int _y) :x(_x), y(_y) {
		}
	};
	int n, m;
	vector<vector<char>> flag;
	queue<Grid>  q;
	bool DFS(vector<vector<char>>& board,int x,int y) {
		q.push({x,y});
		flag[x][y] = true;
		bool res = true;
		if (x == 0 || x == n - 1) { res = res && false; }
		if (y == 0 || y == m - 1) { res = res && false; }
		if (x != 0 && board[x - 1][y] == 'O' && flag[x-1][y] == false) {
			res=  DFS(board,x-1,y) && res;
		}
		if (x != n - 1 && board[x + 1][y] == 'O'&& flag[x + 1][y] == false) {
			res = DFS(board, x + 1, y) && res;
		}
		if (y != 0 && board[x][y - 1] == 'O'&& flag[x][y - 1] == false) {
			res = DFS(board, x, y - 1) && res;
		}
		if (y != m-1 && board[x][y + 1] == 'O'&& flag[x][y + 1] == false) {
			res = DFS(board, x, y + 1) && res;
		}
		return res;
	}
public:
	void solve(vector<vector<char>>& board) {
		n = board.size();
		if (n == 0) { return; }
		m = board[0].size();
		flag = board;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				flag[i][j] = false;
			}
		}
		for (int i = 1; i < n-1; i++) {
			for (int j = 1; j < m-1; j++) {
				if (board[i][j] == 'O' && flag[i][j] == false) {
					if (DFS(board, i, j)) {
						while (!q.empty()) {
							board[q.front().x][q.front().y] = 'X';
							q.pop();
						}
					}
					else
					{
						while (!q.empty()) q.pop();
					}
				}
			}
		}
	}
};

//int main()
//{
//	Solution s;
//	vector<vector<char>> board =
//	{
//{'O','X','O','X','O','O'},{'O','X','O','O','X','O'},{'O','X','O','X','O','O'} 
//	};
//	s.solve(board);
//	system("PAUSE");
//
//	return 0;
//
//}