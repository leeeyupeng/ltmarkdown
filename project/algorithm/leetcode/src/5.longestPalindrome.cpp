#include"leetcode.h"

class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.length();
		int ansstart = 0,anslength=0;
		int offset = 0;
		int offsetlength = 0;
		int inext = 0;
		for (int i = 0; i < n; i++) {
			offset = 0;
			offsetlength = min(i + 1, n - i);

			while (offset < offsetlength&& s[i - offset] == s[i + offset]) {
				offset++;
			}
			if (anslength < (offset << 1) - 1) {
				anslength = (offset << 1) - 1;
				ansstart = i - offset + 1;
			}
			offset = 0;
			inext = i + 1;
			offsetlength = min(i + 1, n - inext);
			while (offset < offsetlength && s[i - offset] == s[inext + offset]) {
				offset++;
			}
			if (anslength < (offset << 1)) {
				anslength = (offset << 1);
				ansstart = i - offset + 1;
			}
		}
		return s.substr(ansstart,anslength);
	}
};

//int main()
//{
//	Solution s;
//	string str = "babad";
//	string ans = s.longestPalindrome(str);
//	cout << ans;
//	system("PAUSE");
//	return 0;
//}