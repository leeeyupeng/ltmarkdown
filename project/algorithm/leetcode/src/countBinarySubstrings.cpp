#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
class Solution {
public:
	int countBinarySubstrings(string s) {
		int n = s.length();
		if (n == 0) { return 0; }
		int lastnum = 0;
		char lastkey = s[0] == '0' ? '1' : '0';
		char curkey = s[0];
		int startindex = 0;
		int ans = 0;
		int i;
		for (i = 0; i < n; i++) {
			if (s[i] == lastkey) {
				ans += min(i - startindex, lastnum);
				lastkey = curkey;
				lastnum = i - startindex;
				startindex = i;
				curkey = s[i];
			}
		}
		ans += min(i - startindex, lastnum);
		return ans;
	}
};

//int main()
//{
//	Solution s;
//	string ss= "10101";
//	int ans = s.countBinarySubstrings(ss);
//	cout << ans;
//	system("PAUSE");
//
//	return 0;
//	 
//}