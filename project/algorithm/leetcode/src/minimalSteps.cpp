#include"leetcode.h"
#define MAX 100
class Solution {
private:
	bool matrix[MAX][MAX] = { false };
public:
	int minimalSteps(vector<string>& maze) {
		int n = maze.size();
		int m = maze[0].length();
		int cost = 0;
		int mnums = 0;
		int s;
		int t;
		int onums = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (maze[i][j] == 'M') { mnums++; }
				else if (maze[i][j] == 'O') { onums++; }
				else if (maze[i][j] == 'S') { s = i * m + j; }
				else if (maze[i][j] == 'T') { t = i * m + j; }
			}
		}
		queue<int>* q1 = new queue<int>();
		queue<int>* q2 = new queue<int>();
		char target = 'T';
		int i, j, index;
		if (mnums != 0) {
			target = 'O';
		}
		q1->push(s); matrix[s/m][s%m] = true;
		while (!q1->empty()) {
			while (!q1->empty()) {
				index = q1->front();
				q1->pop();
				i = index / m;
				j = index - i * m;

				if (maze[i][j] == target) {
					if (target == 'O') { target = 'M'; }
					else if (target == 'M') {
						mnums--; maze[i][j] = '.';
						if (mnums > 0) { target = 'O'; }
						else { target = 'T'; }
					}
					else if (target == 'T') {return cost; }

					while (!q2->empty()) q2->pop();
					q2->push(i * m + j);

					for (int ii = 0; ii < n; ii++) {
						for (int jj = 0; jj < m; jj++) {
							matrix[ii][jj] = false;
						}
					}
					matrix[i][j] = true;
					cost--;
					break;
				}

				if(maze[i][j] == 'T' && target == 'M')
				
				//left //right //up//bottom
				if (j > 0 && maze[i][j - 1] != '#' && matrix[i][j - 1] == false) { 
					q2->push(i * m + j - 1); 
					matrix[i][j - 1] = true;
				}
				if (j < m - 1 && maze[i][j + 1] != '#' && matrix[i][j + 1] == false) {
					q2->push(i * m + j + 1);
					matrix[i][j + 1] = true;
				}
				if (i > 0 && maze[i - 1][j] != '#' && matrix[i - 1][j] == false) { 
					q2->push((i - 1) * m + j); 
					matrix[i-1][j] = true;
				}
				if (i < n - 1 && maze[i + 1][j] != '#' && matrix[i + 1][j] == false) { 
					q2->push((i + 1) * m + j); 
					matrix[i + 1][j] = true;
				}
			}

			while (!q1->empty()) q1->pop();
			queue<int>* temp;
			temp = q1;
			q1 = q2;
			q2 = temp;
			cost++;
		}
		return -1;
	}
};

//int main()
//{
//	Solution s;
//	vector<string> matrix{
//"#..M.",  "..O..", ".S.OM", ".#M#T"
//	};
//	int ans = s.minimalSteps(matrix);
//	cout << ans;
//	system("PAUSE");
//
//	return 0;
//	 
//}