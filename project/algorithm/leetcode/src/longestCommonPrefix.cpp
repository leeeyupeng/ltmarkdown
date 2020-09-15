#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int n = strs.size();
		if (n == 0) { return ""; }
		string& ans = strs[0];
		int i, j;
		int length = ans.length();
		int strlength;
		for (i = 1; i < n; i++) {
			string& str = strs[i];
			strlength = str.length();
			for (j = 0; j < length && j < strlength; j++) {
				if (ans[j] != str[j]) { break; }
			}
			length = j;
		}
		return ans.substr(0,length);
	}
};