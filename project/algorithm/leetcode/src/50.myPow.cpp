class Solution {
public:
	double myPow(double x, int n) {
		double ans = 1.0f;
		double quick = x;
		long long nn = n;
		nn = nn >= 0 ? nn : -nn;
		while (nn != 0) {
			if ((nn & 0x1) == 0x1) { ans *= quick; }
			quick *= quick;
			nn >>= 1;
		}
		return n >= 0 ? ans : 1.0f / ans;
	}
};