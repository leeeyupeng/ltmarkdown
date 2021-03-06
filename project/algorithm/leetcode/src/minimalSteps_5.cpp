#include"leetcode.h"
#define MAX 100
#define MMAX 16
#define OMAX 40
#define INT_MAX (1<<16)
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

	void InitMto(vector<string>& maze, int index) {
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
			for (int j = 0; j < O.size(); j++) {
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

	int greed()
	{
		int ans = INT_MAX;
		int mnums = M.size();
		if (mnums == 0) {
			return StoT;
		}
		bool flag[MMAX];
		for (int i = 0; i < mnums; i++) {
			flag[i] = false;
		}

		int index = 0;
		for (int i = 0; i < mnums; i++) {
			if (StoOtoM[i] != INT_MAX) {
				if (ans > StoOtoM[i]) {
					index = i;
					ans = StoOtoM[i];
				}
			}
		}

		flag[index] = true;
		for (int i = 0; i < mnums - 1; i++) {
			int minindex = 0;
			int mincost = INT_MAX;
			for (int j = 0; j < mnums; j++) {
				if (flag[j] == false && MtoOtoM[index][j] != INT_MAX) {
					if (mincost > MtoOtoM[index][j]) {
						mincost = MtoOtoM[index][j];
						minindex = j;
					}
				}
			}
			if (mincost == INT_MAX) { return INT_MAX; }
			index = minindex;
			ans += mincost;
			flag[index] = true;
		}
		if (MtoT[index] == INT_MAX) { return INT_MAX; }
		ans += MtoT[index];
		return ans;
	}
	int eval(int index, int v) {
		int mnums = M.size();

		if (v == ((1 << mnums) - 1)) {
			return MtoT[index];
		}

		int ans = 0;
		{
			int mincost = INT_MAX;
			for (int i = 0; i < mnums; i++) {
				if (((v >> i) & 0x1) == 0x0 && MtoOtoM[index][i] != INT_MAX) {
					mincost = min(mincost, MtoOtoM[index][i]);
				}
			}
			if (mincost == INT_MAX) { return INT_MAX; }
			ans += mincost;
		}

		int min1 = -1, min2 = -1;
		int tempmin;
		int mincost = 0;
		for (int i = 0; i < mnums; i++) {
			if (((v >> i) & 0x1) == 0x0) {
				min1 = MtoOtoM[index][i], min2 = MtoT[i];
				if (min1 > min2) { tempmin = min1; min1 = min2; min2 = tempmin; }
				for (int j = 0; j < mnums; j++) {
					if (i != j && ((v >> j) & 0x1) == 0x0 && MtoOtoM[i][j] != INT_MAX) {
						if (min2 > MtoOtoM[i][j]) { min2 = MtoOtoM[i][j]; }
						if (min1 > min2) { tempmin = min1; min1 = min2; min2 = tempmin; }
					}
				}
				if (min1 == INT_MAX) { return INT_MAX; }
				if (min2 == INT_MAX) { return INT_MAX; }
				mincost += (min1 + min2);
			}
		}
		ans += mincost;
		{
			int mincost = INT_MAX;
			for (int i = 0; i < mnums; i++) {
				if (((v >> i) & 0x1) == 0x0 && MtoT[i] != INT_MAX) {
					mincost = min(mincost, MtoT[i]);
				}
			}
			if (mincost == INT_MAX) { return INT_MAX; }
			ans += mincost;
		}
		return (ans + 1) / 2;
	}
	struct bb {
		int index;
		int v;
		int cost;
		int eval;

		bb(int _index, int _v, int _cost, int _eval) :index(_index), v(_v), cost(_cost), eval(_eval) {}
		bool operator <(const bb& other) const
		{
			return eval + cost > other.cost + other.eval;
		}
		//bool operator >=(bb& other) const
		//{
		//	return eval + cost >= other.cost + other.eval;
		//}
	};
	int BranchBound()
	{
		int ans = greed();
		int mnums = M.size();
		priority_queue<bb> q;
		unordered_map<int, int> map(65536);
		unordered_map<int, int> mapeval(65536);
		int tempeval;
		for (int i = 0; i < mnums; i++) {
			if (StoOtoM[i] != INT_MAX) {
				q.push(bb(i, 1 << i, StoOtoM[i], eval(i, 1 << i)));
			}
		}
		while (!q.empty()) {
			bb top = q.top();
			q.pop();
			if ((long long)top.cost + (long long)top.eval >= (long long)ans) { break; }
			if (top.v == ((1 << mnums) - 1)) {
				if (top.cost != INT_MAX && top.eval != INT_MAX) {
					ans = min(ans, top.cost + top.eval);
				}
				continue;
			}

			int key = (top.v << 8) + top.index;
			if (map.find(key) != map.end()) {
				if (top.cost > map[key]) { continue; }
				else {
					map[key] = top.cost;
				}
			}
			else {
				map[key] = top.cost;
			}

			for (int i = 0; i < mnums; i++) {
				if (((top.v >> i) & 0x1) == 0x0 && MtoOtoM[top.index][i] != INT_MAX) {
					int key2 = ((top.v + (1 << i)) << 8) + i;
					if (mapeval.find(key2) != mapeval.end()) { tempeval = mapeval[key2]; }
					else {
						tempeval = eval(i, top.v + (1 << i));
						mapeval[key2] = tempeval;
					}
					if (tempeval == INT_MAX) { continue; }
					if (top.cost + MtoOtoM[top.index][i] + tempeval < ans) {
						if (map.find(key2) != map.end() && map[key2] <= top.cost + MtoOtoM[top.index][i]) {
							continue;
						}
						else {
							map[key2] = top.cost + MtoOtoM[top.index][i];
							q.push(bb(i, top.v + (1 << i), top.cost + MtoOtoM[top.index][i], tempeval));
						}
					}
				}
			}
		}
		return ans;
	}
public:
	int minimalSteps(vector<string>& maze) {
		Scan(maze);
		InitSto(maze);
		for (int i = 0; i < M.size(); i++) {
			InitMto(maze, i);
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
			ans = BranchBound();
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
////".#....M#.M", "#.O...#O#O", ".##..##..#", "...#O#.M.#", "..S#..OO..", "#..T#M.###", ".O.....#.#", "...O..##..", ".....O.#.M", "...#......"
////".M..SM..T", ".OMM.MOMM"
////"MMMMM","MS#MM","MM#TO"
////".MM..", "#..M.", ".#..#", "..O..", ".S.OM", ".#M#T", "###..", "....."
//		"...#............#.....#.#.#...###...................#....#.........#...##........#..................","...O......##..............#......#.........#...........#...#....#.........#.........................","..#.#.........#....#........##..............#...................#........O.#...#.........#....#.....",".....#......#..#.#..#........##...........#.....#..................#........#....#..#...............",".#........................#...#...#..#..................................#........#.....#............",".........##......#........##.......#....................#..........O...........#.#.#......#........#","......#....#.......#.......#..#..................#.#............#............#..............#.......","............#..#......#.........#........#......#......#....#.............................#.........","#.#.##....................#...................................#...............#..#..#............#..","..................................................##.#........#...#..................#......#O.....#","#.............M................#..#.......................##.....#..........#..............#.#......","O....#.....#............#...##..........#.......#......#...................#........#...............","O.........................#.#....#..#............................#..........#.......#..........#....",".....O.........#.#..........#..........#.................#........##............#....#.......#......","#......#....#..............#....#............#............#.#.#....#................................","............##..#.....................#.......##..#.#.#........................................#....","...........#.......#...#..#............##..#.........#..#..#..#.........#..#.....#...........##.....","........#......#..#.#...O.....#....#....#............#..........#......#.....................#......","..#.....#..........#....##.#.....................#.#............##...#........##..........#O...#....","........#....#.#..........#..#..................................#..#....#...#.....#.....#.........#.",".#.........#.....................#..#.....#............#.....#.#.........#.......................#..",".....#............................#......##....#....................................#.#........#..#.",".#....#.#.........#............#.......................#.......................#.........#......#...",".......#..........#......................#..#..........#......O.......#..#....#...........O.........",".#O........M....#.##......O.....#......#.#..#...........#..#...#..#..............................#..","....................O...M..........#..........#...#.........#.............#...........#.#...........","#...#.#.....#........#......#.....#...........#...............#.##.....................#..#.........",".....#................#...................##.......#..#.............##...#..#.......................",".....##..........................##............#.............#..........#.#..................#......",".#.....................##.#......#.#.#..........#.#....#................#........#......#...#...#..#",".........#..........#.........O..............#.....M.................#.....#....#...................","...........#......#......##..........#....#.....#..........M...........#....#....##.......#.........","##...................................................#.....#.......##.#.............................","..........#........##..........#..................#......M.#.#.#.........#..........................","....#..#..M#.....M.....#..........M...........#.#............................#......................","..#......#..........#......#..#...##..................#..#...#...................#.......#...#..###.","..................#..#.#.................T..................#.............#..................#......","........#.#...#............#.................#...##.#......#..............#.........................","....#.............#.##.#.........#..##......#.#.#..................................................#","..#.......#.............#.#....#.#.......................#.....#..........#................#........","....#.......................#....#.............#....#....#..........##........#..............#......","#..................#.....O................#....#.#......#.........#......#......................#...","..........#...........#.......O.......##...........#.....................#.........................#","..#................................#.............................#.........#...........#............","..........#.....#.......#..................#............#.........#...#.........O.....#.............","#...#.............#....#........#......#..#........#..........#.............................#.#.....",".......#..........#........O#....#...#.........#...........................................#........",".....##.....#...#..#..#...#....................#......#..#......#...##......O.........#....##.......","................#.....#.........#.............................O.......#............................#",".........#.#.................#.....#....#.........#....#............................................","...#.#...........................#.......#......#............#.#......................###.....O..#..","...................#.#.#......#.......#...............................#......#....#....#............","#.#......#....#........#.#..#.#..........##...##.................#..........#.....................#.",".#....#.......................................#.....#..........#.....M#..........#.....#............","........#.....................#.#............#...............#.#..O.......#...................#.....","....#............................#.......#....#.................................................#...","..................#.#.......#..........#.....#.......#..............#...............#...............",".........................##.........#......#...............#.O..................##............#.....","..##......#..#........#.....................#....#......#.................#...........##.......#....","#..#..#............###..#...............#....#........#..........#..#...........#...............#O..","#..............................#...............#.#....#..#..#..#......#.......#.##............#.....","#.......S.......##.....#...........................###.#...........................#.#............#.",".................................#...........#...........#..........#.....#..#.#...#............#...","...........#....##.....#.............#..#...................................##....................#.","M.#....................#.#...O...............................M......O..................#....#.......","....M#.####........#......................................................#........#................","......#.#..................#................................................##....#.................","...#.............................................###..#...#........................#..#.......#.#...","........#.............O#..#.#....................#..#..#..........#....#.....#......#...#.......#...",".#..##..................#........#..........#........#....#.........##O...............#.....#.......","#.....#.#.#........#.......##....................#..........#.............#...#...#....##........#.#","................#.........#...........#.....#.......##....#..............#..........................","......O........#................##......#.#..................#.........#.............##.............",".#....#.#.........#...#...............#...........##.....#...........#..........M....#............#.","..............#...............O.......#......................#....................#...O..#..........","................#...#.#...#....................#.......#...#..............O.........................",".#................................##.............#...#.#.....#.#................#..#...#............",".....#..............#...............#...............................................................",".......................#....................##..#................#......................#..#.....#..",".........#..#....................#.............#..#......................#.......#..................","#..#........#....................................#.....#..............#..........#......#.#.......#.",".#......................#.....#......#........#....#...#......O#....#.........#....##...............","...........................#.....#...#.........#..#......#.....M......#....#...#............##...O##",".......................#...##............#.........#..............#....#....#..#...#.....#.#........",".#....#.......................#.....#O...#.............................#............#...............","...#.#..............#....M..............#.#.......#...#...#...#..........#........................##",".....#................#.#........#......#....................#.....#................................","....O.....#..................#.#..O...#.........#.......#.#..............#.....#.............#....#.",".......#..#.#..##......#...................#...............#.#.......#.........#....#......#..#....#",".....#.............#...#.......#.#.#........##.....#.#.....#....#......#.#...#................#.....","...............#..........#.#.##...................#.......................#.......##.....#..#.#....",".................#......#............................#...#...##........................#............","#........#........#..........#...#........#.#..#..............#...#.#.....#.#.#.#...................",".........#.#.......###.......#..........#.......#..........................................#........",".#..................#.....#......##.#...........#..........#.....#..................#............#.#","..................................................#.........#..#.#.....##....#...........#..........","......#...........#......#.......#...#.....................#.#............##................#....#..",".#..........................#........#........#.......#........#...#...........###...........#......","#...#...#.......#...................................##........O.........#.....#......#...#..........","#.......#.....#.#....#...#................O...................#..................#.......##........."
//	};
//	int ans = s.minimalSteps(matrix);
//	cout << ans;
//	system("PAUSE");
//
//	return 0;
//
//}