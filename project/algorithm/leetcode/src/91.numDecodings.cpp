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
	int numDecodings(string s) {
		int n = s.size();
		vector<int> dp(n + 1);
		dp[0] = 1;
		for (int i = 0; i < n; i++) {
			dp[i + 1] = 0;
			if (i == 0 && s[i] == '0') { dp[n] = 0; break; }
			else if (i > 0 && s[i] == '0' && s[i-1] == '0') {
				dp[n] = 0; break;
			}
			else if (i > 0 && s[i - 1] == '1') { 
				dp[i+1] += dp[i - 1];
			}
			else if (i > 0 && s[i-1] == '2' && s[i] <= '6') {
				dp[i + 1] += dp[i - 1]; 
			}

			if (s[i] != '0') {
				dp[i + 1] += dp[i];
			}
		}
		return dp[n];
	}
};