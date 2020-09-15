#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool isPrime(int n) {
		for (int i = 2; i <= sqrt(n); i++) {
			if (n%i == 0) {
				return false;
			}
		}
		return true;
	}

	vector<int> FindPrime(int n) {
		vector<int> res;
		vector<bool> p(n + 1,true);
		for (int i = 2; i <= n; i++) {
			if (p[i] == true) {
				res.push_back(i);
				for (int j = i + i; j <= n; j += i) {
					p[j] = false;
				}
			}
		}
		return res;
	}

	//vector<int> FindPrime6(int n) {
	//	vector<int> res;
	//	vector<bool> p(n + 1, true);
	//	for (int i = 3; i + i + 1<= n; i += 3) {
	//		int ii = i + 0 + i + 0 - 1;
	//		if (p[ii] == true) {
	//			res.push_back(ii);
	//			for(int )
	//		}
	//	}
	//	return res;
	//}

	vector<vector<int>> FindPrimeFactor(int n) {
		vector<vector<int>> res;
		vector<bool> p(n + 1, true);
		for (int i = 2; i <= n; i++) {
			if (p[i] == true) {
				if (n%i == 0) {
					int num = 0;
					int temp = n;
					while (temp%i == 0) {
						temp /= i;
						num++;
					}
					res.push_back({i,num});
				}
				for (int j = i + i; j <= n; j += i) {
					p[j] = false;
				}
			}
		}
		return res;
	}
};