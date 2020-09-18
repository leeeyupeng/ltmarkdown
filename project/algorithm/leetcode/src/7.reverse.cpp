#include"leetcode.h"

class Solution {
public:
	int reverse(int x) {
		long long llx = x;
		vector<int> v;
		while (llx != 0) {
			v.push_back(llx%10);
			llx /= 10;
		}

		long long ans = 0;
		for (int i = 0; i < v.size(); i++) {
			ans = ans * 10 + v[i];
		}
		if (ans < INT_MIN) { ans = 0; }
		if (ans > INT_MAX) { ans = 0; }
		return ans;
	}
};

