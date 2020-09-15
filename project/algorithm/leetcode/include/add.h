class Solution {
public:
	int add(int a, int b) {
		while (b!= 0) {
			a = a ^ b;
			b = (((a^b)&b)&(~0x80000000)) << 1;
		}
		return a;
	}
	int mul(int a, int b) {
		int c = 0;
		while (b != 0) {
			b >>= 1;
			a <<= 1;
			if ((b & 0x1) != 0x0) {
				c = add(c , a);
			}
		}
		return c;
	}
};