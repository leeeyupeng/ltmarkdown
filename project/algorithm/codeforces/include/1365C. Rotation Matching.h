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
		vector<int> va(n, 0);
		for (int i = 0; i < n; i++) {
			cin>>va[i];
		}
		vector<int> vb(n + 1, 0);
		int b;
		for (int i = 0; i < n; i++) {
			cin >> b;
			vb[b] = i;
		}
		unordered_map<int, int> map;
		for (int i = 0; i < n; i++) {
			int offset = (vb[va[i]] - i + n) % n;
			if (map.find(offset) == map.end()) {
				map.insert({offset,1});
			}
			else{
				map[offset]++;
			}
		}
		int ans = 0;
		unordered_map<int, int>::iterator iter = map.begin();
		while (iter != map.end()) {
			ans = max(ans, iter->second);
			iter++;
		}
		cout << ans << endl;
	}
};
int maincodeforces()
{
	Solution s;
	s.Solve();
	return 0;
}