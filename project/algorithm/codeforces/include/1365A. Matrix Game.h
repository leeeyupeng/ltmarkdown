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
public:
	void Solve()
	{
		int tc;
		cin >> tc;
		unordered_set<int> srows;
		unordered_set<int> scolumns;
		for (int c = 0; c < tc; c++) {
			int n,m;
			cin >> n>>m;
			srows.clear();
			scolumns.clear();
			int cell = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cin>>cell;
					if (cell == 1) {
						if (srows.find(i) == srows.end()) { srows.insert(i); }
						if (scolumns.find(j) == scolumns.end()) { scolumns.insert(j); }
					}
				}
			}

			int ans = n-srows.size();
			ans = min(ans, m - (int)scolumns.size());
			if (ans & 0x01 == 0x01) {
				cout << "Ashish" << endl;
			}
			else{
				cout << "Vivek" << endl;
			}
		}
	}
};
int maincodeforces()
{
	Solution s;
	s.Solve();
	return 0;
}