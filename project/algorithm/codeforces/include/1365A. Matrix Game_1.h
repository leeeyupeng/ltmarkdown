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
		vector<bool> srows(50,false);
		vector<bool> scolumns(50,false);
		for (int c = 0; c < tc; c++) {
			int n,m;
			cin >> n>>m;
			for (int i = 0; i < n; i++) {
				srows[i] = false;
			}
			for (int j = 0; j < m; j++) {
				scolumns[j] = false;
			}
			int cell = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cin>>cell;
					if (cell == 1) {
						srows[i] = true;
						scolumns[j] = true;
					}
				}
			}

			int inums = 0;
			for (int i = 0; i < n; i++) {
				if (srows[i] == false) { inums++; }
			}
			int jnums = 0;
			for (int j = 0; j < m; j++) {
				if (scolumns[j] == false) { jnums++; }
			}
			int ans = inums;
			ans = min(ans, jnums);
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