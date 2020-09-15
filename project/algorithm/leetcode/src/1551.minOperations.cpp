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
	int minOperations(int n) {
		int average = (2 * (n - 1) + 1 + 1) >> 1;
		int os = 0;
		for (int i = 0; i < n; i++) {
			if (2 * (i) + 1 < average) { os += average - (2 * (i) + 1); }
			else { break; }
		}
		return os;
	}
};