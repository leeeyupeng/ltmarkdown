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

class Solution {
private:
	int cases;
	int n;
	vector<int> va;
	vector<int> vb;

	bool Swap(int index) {
		int i = 0;
		for (i = 0; i <= index; i++) {
			if (va[i] == vb[index] && va[n - 1 - i] == vb[n-1-index]) {
				swap(va[i],va[index]);
				swap(va[n - 1 - i], va[n - 1 - index]);
				break;
			}
			else if (va[i] == vb[n - 1 - index] && va[n - 1 - i] == vb[index]) {
				swap(va[i], va[n - 1 - index]);
				swap(va[n - 1 - i], va[index]);
				break;
			}
		}
		return i <= index;
	}

public:
	void Solve()
	{
		cin >> cases;
		va = vector<int>(501, 0);
		vb = vector<int>(501, 0);
		for (int c = 0; c < cases; c++) {
			cin >> n;

			for (int i = 0; i < n; i++) {
				cin >> va[i];
			}
			for (int i = 0; i < n; i++) {
				cin >> vb[i];
			}

			bool flag = true;
			if (n % 2 == 1) {
				if (va[n / 2] != vb[n / 2]) {
					flag = false;
				}
			}
			if (flag == true) {
				for (int i = n / 2 - 1; i >= 0; i--) {
					if (Swap(i) != true) {
						flag = false;
						break;
					}
				}
			}
			cout << (flag ? "Yes" : "No") << endl;
		}
	}
};
int maincodeforces()
{
	Solution s;
	s.Solve();
	return 0;
}