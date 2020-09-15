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

#define N 500
class Solution {
private:
	int n;
	vector<long long> velements;
	long long ans;
	void DFS(long long value,int index,int start) {
		ans = max(ans, value);

		if (index == 3) {
			return;
		}

		for (int i = start; i < n; i++) {
			DFS(value|velements[i],index+1,i+1);
		}
	}
public:
	void Solve()
	{
		cin >> n;
		velements = vector<long long>(N,0);
		for (int i = 0; i < n; i++) {
			cin>>velements[i];
		}
		ans = 0;
		DFS(0,0,0);
		cout << ans << endl;
	}
};
int maincodeforces()
{
	Solution s;
	s.Solve();
	return 0;
}