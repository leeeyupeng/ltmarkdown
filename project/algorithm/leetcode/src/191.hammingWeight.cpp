#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
using namespace std;

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int ans = 0;
		while (n != 0) {
			ans += (n & 0x1);
			n >>= 1;
		}
		return ans;
	}
};