#include"leetcode.h"

#define MAX 100
#define MMAX 12
#define OMAX 40
class Solution {
private:
	int n, m;
	int S;
	int T;
	vector<int> M;
	vector<int> O;
	int matrix[MAX][MAX];

	bool flagMatrix[MAX][MAX];
	int StoT;
	int StoO[OMAX];
	int MtoO[MMAX][OMAX];
	int MtoT[MMAX];

	int StoOtoM[MMAX];
	int MtoOtoM[MMAX][MMAX];
	//int MtoT[MMAX];
	void Scan(vector<string>& maze) {
		n = maze.size();
		m = maze[0].size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (maze[i][j] == 'M') { matrix[i][j] = M.size(); M.push_back(i*m + j); }
				else if (maze[i][j] == 'O') { matrix[i][j] = O.size();  O.push_back(i*m + j); }
				else if (maze[i][j] == 'S') { matrix[i][j] = 0; S = i * m + j; }
				else if (maze[i][j] == 'T') { matrix[i][j] = 0; T = i * m + j; }
			}
		}
	}

	void InitSto(vector<string>& maze) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				flagMatrix[i][j] = false;
			}
		}
		StoT = INT_MAX;
		for (int i = 0; i < O.size(); i++) {
			StoO[i] = INT_MAX;
		}
		int sx = S / m;
		int sy = S % m;
		queue<int>* q1 = new queue<int>();
		queue<int>* q2 = new queue<int>();
		q1->push(S);
		flagMatrix[sx][sy] = true;
		int cost = 0; 
		while (!q1->empty()) {
			while (!q1->empty()) {
				int grid = q1->front();
				q1->pop();
				int x = grid / m;
				int y = grid % m;
				if (grid == T) { StoT = cost; }
				if (maze[x][y] == 'O') { StoO[matrix[x][y]] = cost; }

				if (x > 0 && flagMatrix[x - 1][y] == false && maze[x - 1][y] != '#') { flagMatrix[x - 1][y] = true; q2->push((x - 1)*m + y); }
				if (x < n - 1 && flagMatrix[x + 1][y] == false && maze[x + 1][y] != '#') { flagMatrix[x + 1][y] = true; q2->push((x + 1)*m + y); }
				if (y > 0 && flagMatrix[x][y - 1] == false && maze[x][y - 1] != '#') { flagMatrix[x][y - 1] = true; q2->push(x * m + y - 1); }
				if (y < m - 1 && flagMatrix[x][y + 1] == false && maze[x][y + 1] != '#') { flagMatrix[x][y + 1] = true; q2->push(x * m + y + 1); }
			}

			cost++;
			queue<int> *temp;
			temp = q1;
			q1 = q2;
			q2 = temp;
		}
	}

	void InitMto(vector<string>& maze,int index) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				flagMatrix[i][j] = false;
			}
		}
		MtoT[index] = INT_MAX;
		for (int i = 0; i < O.size(); i++) {
			MtoO[index][i] = INT_MAX;
		}

		int mx = M[index] / m;
		int my = M[index] % m;
		
		queue<int>* q1 = new queue<int>();
		queue<int>* q2 = new queue<int>();
		q1->push(M[index]);
		flagMatrix[mx][my] = true;
		int cost = 0;
		while (!q1->empty()) {
			while (!q1->empty()) {
				int grid = q1->front();
				q1->pop();
				int x = grid / m;
				int y = grid % m;
				if (grid == T) { MtoT[index] = cost; }
				if (maze[x][y] == 'O') { MtoO[index][matrix[x][y]] = cost; }

				if (x > 0 && flagMatrix[x - 1][y] == false && maze[x - 1][y] != '#') { flagMatrix[x - 1][y] = true; q2->push((x - 1)*m + y); }
				if (x < n - 1 && flagMatrix[x + 1][y] == false && maze[x + 1][y] != '#') { flagMatrix[x + 1][y] = true; q2->push((x + 1)*m + y); }
				if (y > 0 && flagMatrix[x][y - 1] == false && maze[x][y - 1] != '#') { flagMatrix[x][y - 1] = true; q2->push(x * m + y - 1); }
				if (y < m - 1 && flagMatrix[x][y + 1] == false && maze[x][y + 1] != '#') { flagMatrix[x][y + 1] = true; q2->push(x * m + y + 1); }
			}

			cost++;
			queue<int> *temp;
			temp = q1;
			q1 = q2;
			q2 = temp;
		}
	}

	void InitStoOtoM() {
		for (int i = 0; i < M.size(); i++) {
			StoOtoM[i] = INT_MAX;
		}
		for (int i = 0; i < M.size(); i++) {
			for (int j = 0; j < O.size();j++) {
				if (StoO[j] != INT_MAX && MtoO[i][j] != INT_MAX) {
					StoOtoM[i] = min(StoOtoM[i], StoO[j] + MtoO[i][j]);
				}
			}
		}
	}
	void InitMtoM(int index) {
		for (int i = 0; i < M.size(); i++) {
				MtoOtoM[index][i] = INT_MAX;
		}
		for (int i = 0; i < M.size(); i++) {
			for (int j = 0; j < O.size(); j++) {
				if (MtoO[index][j] != INT_MAX && MtoO[i][j] != INT_MAX) {
					MtoOtoM[index][i] = min(MtoOtoM[index][i], MtoO[index][j] + MtoO[i][j]);
				}
			}
		}
	}

	int Dynamic()
	{
		int mnums = M.size();
		int dp[1 << MMAX][MMAX];
		dp[0][0] = 0;

		for (int i = 0; i < (1 << mnums); i++) {
			for (int j = 0; j < mnums; j++) {
				dp[i][j] = INT_MAX;
			}
		}
		for (int i = 0; i < mnums; i++)
		{
			dp[1 << i][i] = StoOtoM[i];
		}

		for (int i = 1; i < (1 << mnums); i++) {
			for (int j = 0; j < mnums; j++) {
				if (i >> j & 0x1 == 0x1) {
					for (int k = 0; k < mnums; k++) {
						if (i >> k & 0x1 == 0x1) {
							if (dp[i & ~(1 << j)][k] != INT_MAX && MtoOtoM[k][j] != INT_MAX) {
								dp[i][j] = min(dp[i][j], dp[i & ~(1 << j)][k] + MtoOtoM[k][j]);
							}
						}
					}
				}
			}
		}

		int ans = INT_MAX;
		for (int i = 0; i < mnums; i++) {
			if (dp[(1 << mnums) - 1][i] != INT_MAX && MtoT[i] != INT_MAX) {
				ans = min(ans, dp[(1 << mnums) - 1][i] + MtoT[i]);
			}
		}
		return ans;
	}
public:
	int minimalSteps(vector<string>& maze) {
		Scan(maze);
		InitSto(maze);
		for (int i = 0; i < M.size(); i++) {
			InitMto(maze,i);
		}

		InitStoOtoM();
		for (int i = 0; i < M.size(); i++) {
			InitMtoM(i);
		}

		int ans = INT_MAX;
		if (M.empty()) {
			ans = StoT;
		}
		else
		{
			ans = Dynamic();
		}

		if (ans == INT_MAX) { return -1; }
		return ans;
	}
};

//int main()
//{
//	Solution s;
//	vector<string> matrix{
////".MM..", "#..M.", ".#..#", "..O..", ".S.OM", ".#M#T", "###..", "....."
////		"S#O", "M.#", "M.T"
//		//dfs��ʱ
////		"MMMMM","MS#MM","MM#TO"
////"..#..",".S#..","..#T#"
////"##TOO#O#", "OO##O.S#", "###.O###", "#..O#O##"
////"S.#.M","O.#.O","M.#.T"
//
////"TOO", ".##", "OMS", ".O.", "#OO"
//".#....M#.M", "#.O...#O#O", ".##..##..#", "...#O#.M.#", "..S#..OO..", "#..T#M.###", ".O.....#.#", "...O..##..", ".....O.#.M", "...#......"
//	};
//	int ans = s.minimalSteps(matrix);
//	cout << ans;
//	system("PAUSE");
//
//	return 0;
//
//}