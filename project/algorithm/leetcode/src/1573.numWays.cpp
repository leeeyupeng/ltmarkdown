#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int numWays(string s) {
		int n = s.length();
		long long ans = 1;
		int onenums = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') { onenums++; }
		}
		if (onenums == 0) {
			if (n < 3) { return 0; }
			else {
				ans = 1;
				ans *= (n - 1);
				ans *= (n - 2);
				ans /= 2;
				ans %= 1000000000 + 7;
				return ans;
			}
		}
		if (onenums % 3 != 0) { return 0; }
		int split[6];
		split[0] = 0;
		int temponenums = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') { 
				temponenums++; 
				if (temponenums == 1) {
					split[0] = i;
				}
				if (temponenums == onenums / 3) {
					split[1] = i;
				}
				if (temponenums == onenums / 3 + 1) {
					split[2] = i;
				}
				if (temponenums == onenums * 2 / 3) {
					split[3] = i;
				}
				if (temponenums == onenums * 2 / 3 + 1) {
					split[4] = i;
				}
				if (temponenums == onenums) {
					split[5] = i;
				}
			}
		}

		ans = 1;
		ans *= (split[2] - split[1]);
		ans *= (split[4] - split[3]);
		ans %= 1000000000 + 7;
		return ans;
	}
};

//int main()
//{
//	Solution s;
//	string str = "10101";
//	int ans = s.numWays(str);
//	system("PAUSE");
//	return 0;
//}