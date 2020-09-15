#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;

class Solution {
public:
	int countSubstrings(string s) {
		int n = s.length();
		int ans = 0;
		int ii, jj;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				ii = i;
				jj = j;
				while (ii < jj) {
					if (s[ii] != s[jj]) { break; }
					ii++; jj--;
				}
				if (ii < jj) { continue; }
				ans++;
			}
		}
		return ans;
	}
};

//int main()
//{
//	Solution s;
//	string str = "aba";
//	int ans = s.countSubstrings(str);
//	cout << ans;
//	system("PAUSE");
//	return 0;
//}