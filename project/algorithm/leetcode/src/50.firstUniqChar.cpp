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
using namespace std;

class Solution {
public:
	char firstUniqChar(string s) {
		unordered_map<char, int> us;
		int n = s.length();
		for (int i = 0; i < n; i++) {
			us[s[i]]++;
		}
		for (int i = 0; i < n; i++) {
			if (us[s[i]] == 1) { return s[i]; }
		}
		return ' ';
	}
};