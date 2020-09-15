#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

#define NMAX 1000
class Solution {
private:
	int n;
	//int matrix[NMAX][NMAX];
	map<int, int> matrix;
	void update(int x, int y) {
		for (int i = x; i <= n; i += (i&(-i))) {
			for (int j = y; j <= n; j += (j&(-j))) {
				matrix[i*n + j] += 0x1;
			}
		}
	}
	int getSum(int x, int y) {
		if (x == 0 || y == 0) { return 0; }
		int result = 0;
		for (int i = x; i > 0; i -= (i&(-i))) {
			for (int j = y; j > 0; j -= (j&(-j))) {
				result += matrix[i*(n) + j];
			}
		}
		return result;
	}
public:
	void init(int _n) {
		n = _n;
		//for (int i = 0; i <= n; i++) {
		//	for (int j = 0; j <= n; j++) {
		//		matrix[i*(n + 1) + j] = 0;
		//	}
		//}
	}
	void change(int x1, int y1, int x2, int y2) {
		for (int i = x1; i <= x2; i++) {
			for (int j = y1; j <= y2; j++) {
				update(i,j);
			}
		}
	}
	int query(int x, int y) {
		int res = 0;
		res += getSum(x,y);
		res -= getSum(x-1, y);
		res -= getSum(x, y-1);
		res += getSum(x - 1, y - 1);
		return (res % 0x2 + 0x2) % 0x2;
	}

	void solve()
	{
		int x;
		cin >> x;
		for (int i = 0; i < x; i++) {
			int n = 0;
			cin >> n;
			init(n);
			int instructionsnums;
			cin >> instructionsnums;
			char instructions;
			int x1, y1, x2, y2;
			for (int j = 0; j < instructionsnums; j++) {
				cin >> instructions;
				if (instructions == 'C') {
					cin >> x1 >> y1 >> x2 >> y2;
					change(x1, y1, x2, y2);
				}
				else if (instructions == 'Q') {
					cin >> x1 >> y1;
					cout <<query(x1, y1) << endl;
				}
			}
		}
	}
};

//int main() {
//	Solution s;
//	s.solve();
//	return 0;
//}
