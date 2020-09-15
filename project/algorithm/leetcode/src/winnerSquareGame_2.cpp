#include"leetcode.h"
class Solution {
private:
	vector<int> square;
	vector<char> vv;
public:
	char DFS(int index) {
		if (vv[index] != -1) { return vv[index]; }
		for (int j = 1; square[j]<= index; j++) {
			if (DFS(index - square[j]) == 0) {
				vv[index] = 1;
				return vv[index];
			}
		}
		vv[index] = 0;
		return vv[index];
	}
	bool winnerSquareGame(int n) {
		vv = vector<char>(n + 1, -1);
		vv[0] = 0;
		vv[1] = 1;
		int nn = sqrt(n);
		for (int i = 0; i <= nn + 1; i++) {
			square.push_back(i * i);
		}
		return DFS(n) == 1;
	}
};

//int main()
//{
//	Solution s;
//	bool ans = s.winnerSquareGame(17);
//	cout << ans;
//	system("PAUSE");
//
//	return 0;
//
//}