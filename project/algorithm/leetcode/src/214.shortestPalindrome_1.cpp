#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
using namespace std;

class Solution {
public:
	string shortestPalindrome(string s) {
		int n = s.length();
		int ansright = 0;
		int left,right;
		for (int i = n - 1; i >= 0; i--) {
			left = 0; right = i;
			while (left < right && s[left] == s[right]) { left++; right--; }
			if (left >= right) { ansright = i; break; }
		}
		string ans;
		int nn = n - 1;
		while (nn > ansright) {
			ans+=s[nn];
			nn--;
		}
		ans += s;
		return ans;
	}
};

//int main()
//{
//	Solution s;
//	string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
//	for (int i = 0; i < 100000; i++) { str += "a"; }
//	string ans = s.shortestPalindrome(str);
//	cout << ans;
//	system("PAUSE");
//	return 0;
//}