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
		int mid = n >> 1;
		int offset = 0;
		string ans;
		for (int i = mid; i >= 0; i--) {
			if (i <= n - i - 1) {
				offset = 0;
				while (i - offset >= 0 && s[i - offset] == s[i + offset]) {
					offset++;
				}
				if (i - offset < 0) {
					int nn = n - 1;
					while (nn > i + offset - 1) {
						ans.push_back(s[nn]);
						nn--;
					}
					ans += s;
					break;
				}
			}
			if (i > 0) {
				offset = 0;
				while (i - offset - 1 >= 0 && s[i - offset - 1] == s[i + offset]) {
					offset++;
				}
				if (i - offset - 1< 0) {
					int nn = n - 1;
					while (nn > i + offset - 1) {
						ans.push_back(s[nn]);
						nn--;
					}
					ans += s;
					break;
				}
			}
		}
		return ans;
	}
};