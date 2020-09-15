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
	bool isPowerOfThree(int n) {
		if (n == 0) { return false; }
		while (n != 1) {
			if (n % 3 != 0) { return false; }
			n /= 3;
		}
		return true;
	}
};

//int main() {
//
//	Solution s;
//	int ans = s.isPowerOfThree(27);
//	cout << "ans:" << ans << endl;
//	system("PAUSE");
//
//	return 0;
//}