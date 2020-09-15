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
	bool threeConsecutiveOdds(vector<int>& arr) {
		int count = 0;
		int n = arr.size();
		for (int i = 0; i < n; i++) {
			if ((arr[i] & 0x1) == 0x1) { 
				count++;
				if (count == 3) { return true; }
			}
			else { count = 0; }
		}
		return false;
	}
};