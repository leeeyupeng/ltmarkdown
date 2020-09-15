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
	string a;
	string b;
	vector<vector<int>> dp;
public:
	void Solve()
	{
		cin >> cases;
		dp = vector<vector<int>>(2002, vector<int>(2002,0));
		for (int c = 0; c < cases; c++) {
			cin >> n;
			cin >> a;
			cin >> b;
			{
				string aa = a;
				string bb = b;
				sort(aa.begin(), aa.end());
				sort(bb.begin(), bb.end());
				int i = 0;
				for (i = 0; i < n; i++) {
					if (aa[i] != bb[i]) { cout << -1 << endl; break; }
				}
				if (i != n) { continue; }
			}
			for (int i = n; i >= 1; i--) {
				for (int j = n; j >=1; j--) {
					if (a[i-1] == b[j-1]) {
						dp[i][j] = dp[i+1][j+1];
					}
					else {
						dp[i][j] = dp[i][j + 1];
						dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
					}
				}
			}

			int ans = dp[1][1];
			cout << ans << endl;
		}
	}
};
int maincodeforces()
{
	Solution s;
	s.Solve();
	return 0;
}