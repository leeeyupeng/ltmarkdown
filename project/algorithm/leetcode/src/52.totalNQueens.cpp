#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
	int N;
	vector<vector<bool>> flag;
	int ans;
	bool check(int i, int j) {
		if (flag[i][j] == true) { return false; }

		for (int ii = 0; ii < N; ii++) {
			if (flag[ii][j] == true) { return false; }
		}
		for (int jj = 0; jj < N; jj++) {
			if (flag[i][jj] == true) { return false; }
		}
		int index = 1;
		while (i - index >= 0 && j - index >= 0) {
			if (flag[i - index][j - index] == true) { return false; }
			index++;
		}
		index = 1;
		while (i + index < N && j + index < N) {
			if (flag[i + index][j + index] == true) { return false; }
			index++;
		}
		index = 1;
		while (i + index < N && j - index >=0) {
			if (flag[i + index][j - index] == true) { return false; }
			index++;
		}
		index = 1;
		while (i - index >= 0&& j + index < N) {
			if (flag[i - index][j + index] == true) { return false; }
			index++;
		}
		return true;
	}
	void DFS(int index)
	{
		if (index == N) {
			ans++;
			return;
		}
		int i = index;
		for (int j = 0; j < N; j++) {
			if (check(i,j)) {
				flag[i][j] = true;
				DFS(index + 1);
				flag[i][j] = false;
			}
		}
		return;
	}
	int totalNQueens(int n) {
		N = n;
		ans = 0;
		flag.insert(flag.begin(), n, vector<bool>(n, false));
		DFS(0);
		return ans;
	}
};

//int main() {
//
//	Solution s;
//	int ans = s.totalNQueens(4);
//	cout << "ans:" << ans << endl;
//	system("PAUSE");
//
//	return 0;
//}