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
	int countPrimes(int n) {
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			v[i] = true;
		}

		int ans;
		int value;
		for (int i = 2; i < n; i++) {
			if (v[i] == true) {
				value = i + i;				
				while (value < n) {
					v[value] = false;
					value += i;
				}
				ans++;
			}
		}
		return ans;
	}
};