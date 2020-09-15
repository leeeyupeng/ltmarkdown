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
	unordered_map<char, int> map;
public:
	void Solve()
	{
		cin >> cases;
		for (int c = 0; c < cases; c++) {
			cin >> n;
			cin >> a;
			cin >> b;

			map.clear();
			int ans = 0;
			int i = n-1, j = n-1;
			while (i >= 0 && j >= 0) {
				if (a[i] == b[j]) { i--; j--; }
				else if(map.find(b[j])!=map.end() && map[b[j]] > 0){
					map[b[j]] --;
					j--;
				}
				else {
					if (map.find(a[i]) == map.end()) {
						map.insert({a[i],1});
					}
					else {
						map[a[i]]++;
					}
					ans++;
					i--;
				}
			}
			while (j >= 0) {
				if (map.find(b[j]) != map.end() && map[b[j]] > 0) {
					map[b[j]] --;
					j--;
				}
				else {
					break;
				}
			}
			if (j==-1) {
				cout << ans << endl;
			}
			else
			{
				cout << -1 << endl;
				map.clear();
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