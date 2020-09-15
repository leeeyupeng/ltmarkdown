#include"leetcode.h"
#define MAX 100
class Solution {
private:
	vector<string> maze;
	int n;
	int m;
	int s;
	int t;
	vector<int> mv;
	vector<int> ov;
	int moMatrix[17][41];
	int mmMatrix[18][18];
	int ansgreed;
	int ans;

	void InitmoMatrix() {
		vector<int> smv = mv;
		vector<int> otv = ov;
		smv.insert(smv.begin(), s);
		otv.push_back(t);

		int mvnums = smv.size();
		unordered_map<int, int> mmap;
		for (int i = 0; i < smv.size(); i++) {
			mmap.insert({ smv[i], i });
		}

		int ovnums = otv.size();
		unordered_map<int, int> omap;
		for (int i = 0; i < otv.size(); i++) {
			omap.insert({ otv[i], i });
		}

		for (int i = 0; i < smv.size(); i++) {
			bool flagMatrix[MAX][MAX] = { false };

			int mindex = i;

			queue<int>* q1 = new queue<int>();
			queue<int>* q2 = new queue<int>();
			q1->push(smv[i]);
			int nums = ovnums;
			int cost = 0;
			flagMatrix[smv[i]/m][smv[i]%m] = true;
			while (!q1->empty() && nums > 0) {
				while (!q1->empty() && nums > 0) {
					int xy = q1->front();
					q1->pop();
					int x = xy / m;
					int y = xy % m;
					
					if (maze[x][y] == 'O' || maze[x][y] == 'T') {
						int oindex = omap[xy];
						moMatrix[i][oindex] = cost;
						nums--;
					}

					if (x > 0 && flagMatrix[x - 1][y] == false && maze[x - 1][y] != '#') { 
						flagMatrix[x-1][y] = true; 
						q2->push((x - 1) * m + y); }
					if (x < n - 1 && flagMatrix[x + 1][y] == false && maze[x + 1][y] != '#') {
						flagMatrix[x+1][y] = true; 
						q2->push((x + 1) * m + y); }
					if (y > 0 && flagMatrix[x][y - 1] == false && maze[x][y - 1] != '#') {
						flagMatrix[x][y-1] = true; 
						q2->push((x)* m + y - 1); }
					if (y < m - 1 && flagMatrix[x][y + 1] == false && maze[x][y + 1] != '#') { 
						flagMatrix[x][y+1] = true;
						q2->push((x)* m + y + 1); }
				}

				cost++;
				queue<int>* temp;
				temp = q2;
				q2 = q1;
				q1 = temp;
			}
		}
	}
	void InitmmMatrix() {
		int mmnums = 2 + mv.size();
		for (int i = 0; i < mv.size(); i++) {
			for (int j = 0; j < ov.size(); j++) {
				if (moMatrix[0][j] != INT_MAX && moMatrix[i + 1][j] != INT_MAX) {
					mmMatrix[0][i + 1] = min(mmMatrix[0][i + 1], moMatrix[0][j] + moMatrix[i + 1][j]);
				}
			}
			mmMatrix[i+1][0] = mmMatrix[0][i + 1];
		}
		

		for (int i = 0; i < mv.size(); i++) {
			for (int j = i + 1; j < mv.size(); j++) {
				for (int k = 0; k < ov.size(); k++) {
					if (moMatrix[i + 1][k] != INT_MAX && moMatrix[j + 1][k] != INT_MAX) {
						mmMatrix[i + 1][j + 1] = min(mmMatrix[i + 1][j + 1], moMatrix[i + 1][k] + moMatrix[j + 1][k]);
					}
				}

				mmMatrix[j + 1][i + 1] = mmMatrix[i + 1][j + 1];
			}
		}

		int tindex = mv.size() + 1;

		mmMatrix[0][tindex] = moMatrix[0][ov.size()];
		mmMatrix[tindex][0] = mmMatrix[0][tindex];
		for (int i = 0; i < mv.size(); i++) {
			mmMatrix[tindex][i + 1] = moMatrix[i+1][ov.size()];
			mmMatrix[i + 1][tindex] = mmMatrix[tindex][i + 1];
		}
	}

	int greed() {
		int smt = mv.size() + 2;
		vector<bool> flag(smt,false);
		int index = 0;
		int nextindex = -1;

		int nums = smt;
		int cost = 0;
		while (--nums > 1) {
			flag[index] = true;
			nextindex = -1;
			for (int i = 0; i < smt - 1; i++) {
				if (flag[i] == false) {
					if (nextindex == -1) { if (mmMatrix[index][i] != INT_MAX) { nextindex = i; } }
					else if (mmMatrix[index][i] < mmMatrix[index][nextindex]) { nextindex = i; }
				}
			}
			if (nextindex == -1) { 
				return -1; 
			}
			cost += mmMatrix[index][nextindex];
			index = nextindex;
		}
		if (mmMatrix[index][smt - 1] == INT_MAX) { return -1; }
		cost += mmMatrix[index][smt-1];
		return cost;
	}
	void dfs(int cost,int index,vector<bool>& flag) {
		if (cost >= ans) { return; }
		
		bool tflag = true;
		for (int i = 0; i < flag.size() - 1; i++) {
			if (flag[i] == false) {
				tflag = false;
				flag[i] = true;
				dfs(cost+mmMatrix[index][i],i,flag);
				flag[i] = false;
			}
		}
		if (tflag == true) {
			ans = min(ans,cost + mmMatrix[index][flag.size() - 1]);
		}
	}
public:
	int minimalSteps(vector<string>& maze) {
		this->maze = maze;
		n = maze.size();
		m = maze[0].length();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (maze[i][j] == 'M') { mv.push_back(i*m + j); }
				else if (maze[i][j] == 'O') { ov.push_back(i*m + j); }
				else if (maze[i][j] == 'S') { s = i * m + j; }
				else if (maze[i][j] == 'T') { t = i * m + j; }
			}
		}

		for (int i = 0; i < mv.size() + 1; i++) {
			for (int j = 0; j < ov.size() + 1; j++) {
				moMatrix[i][j] = INT_MAX;
			}
		}
		for (int i = 0; i < mv.size() + 2; i++) {
			for (int j = 0; j < mv.size() + 2; j++) {
				mmMatrix[i][j] = INT_MAX;
			}
		}
		for (int i = 0; i < mv.size() + 2; i++) {
			mmMatrix[i][i] = 0;
		}
 		InitmoMatrix();
		InitmmMatrix();

		ansgreed = greed();
		if (ansgreed == -1) { return -1; }

		ans = ansgreed;
		int smt = mv.size() + 2;
		vector<bool> flag(smt,false);
		dfs(0,0,flag);
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
//		"MMMMM","MS#MM","MM#TO"
//	};
//	int ans = s.minimalSteps(matrix);
//	cout << ans;
//	system("PAUSE");
//
//	return 0;
//
//}