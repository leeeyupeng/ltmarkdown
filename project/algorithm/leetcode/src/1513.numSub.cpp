#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<stack>

#include<cmath>
using namespace std;

class Solution {
public:
	int numSub(string s) {
		int n = s.length();
		long long ans = 0;
		int left = -1;
		int right = -1;
		long long lrlength;
		int i = 0;
		for (i = 0; i < n; i++) {
			if (s[i] == '1' && left == -1) { left = i; }
			else if (s[i] == '0' && left != -1) {
				right = i;
				lrlength = (right - left);
				ans += (lrlength * (lrlength + 1)) >> 1;
				ans %= 1000000000 + 7;
				left = -1;
				right = -1;
			}
		}
		if (left != -1) {
			right = i;
			lrlength = (right - left);
			ans += (lrlength * (lrlength + 1)) >> 1;
			ans %= 1000000000 + 7;
		}
		return ans;
	}
};