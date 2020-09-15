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
		int offset = 0;
		int offsetlength = 0;
		int inext = 0;
		for (int i = 0; i < n; i++) {
			offset = 0;
			offsetlength = min(i + 1, n - i);

			while (offset < offsetlength&& s[i - offset] == s[i + offset]) {
				ans++;
				offset++;
			}
			offset = 0;
			inext = i + 1;
			offsetlength = min(i + 1, n - inext);
			while (offset < offsetlength && s[i - offset] == s[inext + offset]) {
				ans++;
				offset++;
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