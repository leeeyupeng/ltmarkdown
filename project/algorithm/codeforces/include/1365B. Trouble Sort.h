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
		int t;
		cin >> t;
		vector<vector<int>> velements(500, vector<int>(2,0));
		for (int it = 0; it < t; it++) {
			int n;
			cin >> n;
			bool bsort = true;
			for (int i = 0; i < n; i++) {
				cin>>velements[i][0];
				if (i > 0) {
					bsort = bsort && (velements[i][0] >= velements[i - 1][0]);
				}
			}
			bool type0=false, type1 =false; 
			for (int i = 0; i < n; i++) {
				cin >> velements[i][1];
				type0 = type0 || velements[i][1] == 0;
				type1 = type1 || velements[i][1] == 1;
			}
			bool ans = bsort||(type0 && type1);
			if (ans) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
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