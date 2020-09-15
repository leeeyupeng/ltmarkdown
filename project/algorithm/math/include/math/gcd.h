#pragma once
#include <iostream>
using namespace std;

class Solution {
public:
	int gcd(int a, int b) {
		if (a < b)
			std::swap(a, b);
		return b == 0 ? a : gcd(b, a % b);
	}

	int gcd_stein(int a, int b) {
		if (a < b)
			std::swap(a, b);

		if (b == 0) {
			return a;
		}
		else if ((a & 0x01) == 0 && (b & 0x01) == 0) {
			return gcd_stein(a >> 1, b >> 1)<<1;
		}
		else if ((a & 0x01) == 0)
		{
			return gcd_stein(a >> 1,b);
		}
		else if ((b & 0x01) == 0)
		{
			return gcd_stein(a, b >> 1);
		}
		else
		{
			return gcd_stein((a - b) >> 1, b);
		}
	}
};
