
#ifndef  _LTMATH_H
#define _LTMATH_H
namespace lt {
	int round(float r) {
		return r > 0.0 ? (int)(r + 0.5f) : (int)(r - 0.5f);
	}
}
#endif