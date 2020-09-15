#pragma once
#include <iostream>
using namespace std;
class Solution {
public:
	double abs(double x) {
		if (x < 0)return -x;
		else return x;
	}
	double sqrt(double x) {
		double eps = 1e-12;
		double t = x;
		while (abs(t - x / t) > eps * t) {
			t = (t + x / t) / 2.0;
		}
		return t;
	}

	double sqrt2(double x) {
		double eps = 1e-12;
		double t = x;
		double lastt;
		do {
			lastt = t;
			t = (t + x / t) / 2.0;
		} while (abs(t-lastt) > eps);
		return t;
	}

	double sqrt3(double x) {
		double eps = 1e-12;
		double left = 0, right = x;
		double m = x;
		double lastt;
		do{
			lastt = m;
			m = (left + right) * 0.5f;
			if (m*m >= x) {
				right = m;
			}
			else {
				left = m;
			}
		} while (abs(m - lastt) > eps);
		return m;
	}
	double pow2(double base, int n) {
		double pow = 1;
		while (n > 0) {
			pow *= base;
			n--;
		}
		return pow;
	}
	double pow(double base, int n) {
		double res=1;
		while (n != 0) {
			res *= (n&0x1)==0x0?1:base;
			n >>= 1;
			base *= base;
		}
		return res;
	}
	double sqrt(double x,int n) {
		double eps = 1e-12;
		double t = x;
		double lastt;
		do {
			lastt = t;
			t = ((n-1)*t + x / pow(t,n-1)) / n;
		} while (abs(t - lastt) > eps);
		return t;
	}
	
	double pow1(double base, double exponent) {
		double eps = 1e-12;
		int n = exponent;
		double p = pow(base, n);
		double s = exponent - n + 1e-13;
		int bit = 1;
		while (s > eps) {
			bit *= 10;
			int m = (s * bit);
			s = (s * bit -  m) / bit;
			if (m != 0) {
				double pp = pow(base, m);
				p *= sqrt(pp, bit);
			}
		}
		return p;
	}

	double log(double x,double base) {

	}
	double exp(double x) {
		double eps = 1e-12;
		double last = x;
		double res=0;
		double xx=1;
		double zz = 1;
		int index = 1;
		while (abs(res - last) > eps) {
			last = res;
			res += xx / zz;
			xx *= x;
			zz *= index;
			index++;
		}
		return res;
	}
	double ln(double x) {
		double eps = 1e-12;
		double last = x - 1;
		double res = 0;
		double xx = -1;
		double zz = 1;
		int index = 1;
		while (abs(res - last) > eps) {
			last = res;
			xx *= -(x - 1);
			zz = index;
			res += xx / zz;			
			index++;
		}
		return res;
	}
	double pow2(double base, double exponent) {
	}
	int mod(int exp1, int exp2) {
		return exp1 - exp2 * (int)(exp1 / exp2);
	}
	int mod2(int exp1, int exp2) {
		while (exp1 > exp2) { exp1 -= exp2; }
		while (exp1 < -exp2) { exp1 += exp2; }
		return exp1;
	}
#define PI 3.1415926535
	double deg2rad(double x) {
		return x / 180.0f * PI;
	}
	double sin(double x) {
		double eps = 1e-12;
		double last = x;
		double y = 0;
		int index = 1;
		double xx = x;
		double zz = 1;
		y += xx / zz;
		do {
			last = y;
			index++;
			xx *= x * x;
			zz *= ((index-1) * 2) * ((index-1) * 2 + 1);
			if ((index & 0x1) == 0x0) {
				y -= xx / zz;
			}
			else {
				y += xx / zz;
			}
			
		} while (abs(y - last) > eps);
		return y;
	}
};