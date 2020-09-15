#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

#define NMAX 1001
class Solution {
private:
	int n;
	int matrix[NMAX][NMAX];
	void update(int x, int y) {
		for (int i = x; i <= n; i += (i&(-i))) {
			for (int j = y; j <= n; j += (j&(-j))) {
				matrix[i][j] += 0x1;
			}
		}
	}
	int getSum(int x, int y) {
		int result = 0;
		for (int i = x; i > 0; i -= (i&(-i))) {
			for (int j = y; j > 0; j -= (j&(-j))) {
				result += matrix[i][j];
			}
		}
		return result;
	}
public:
	void init(int _n) {
		n = _n;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				matrix[i][j] = 0;
			}
		} 
	}
	void change(int x1, int y1, int x2, int y2) {
		update(x1,y1);
		update(x2 + 1, y1);
		update(x1, y2 + 1);
		update(x2+1, y2+1);
	}
	int query(int x, int y) {
		int res = 0;
		res += getSum(x,y);
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
					cout << query(x1, y1) << endl;
				}
			}

			if (x != 0)cout << endl;
		}
	}
};

//int main() {
//	Solution s;
//	s.solve();
//	return 0;
//}
