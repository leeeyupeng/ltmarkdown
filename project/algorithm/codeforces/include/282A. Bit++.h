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
		int n;
		cin >> n;
		string s;
		int x = 0;
		for (int i = 0; i < n; i++) {
			cin >> s;
			if (s == "++X" || s == "X++") { x++; }
			else if (s == "--X" || s == "X--") { x--; }
		}
		cout<<x;
	}
};
int maincodeforces()
{
	Solution s;
	s.Solve();
	return 0;
}