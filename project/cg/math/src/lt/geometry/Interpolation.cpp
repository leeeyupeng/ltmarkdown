#include"lt/math/Vector2.hpp"
#include"lt/math/Vector3.hpp"
#include"lt/geometry/Interpolation.hpp"
using namespace lt;
//float* lt::InterpolationTriangle(Vector2<float> p, Vector2<float> a, Vector2<float> b, Vector2<float> c)
//{
//	Vector2<float> a1b1 = p - a;
//	Vector2<float> a2b2 = c - b;
//	Vector2<float> a2a1 = a - b;
//	Vector2<float> a1a2 = b - a;
//	float u = (a2b2.x * a2a1.y - a2a1.x * a2b2.y) / (a1b1.x * a2b2.y - a2b2.x * a1b1.y);
//	Vector2<float> aintersected = a + a1b1 * u;
//
//	float arr[3];
//	arr[0] = (p - a).magnitude() / (aintersected - a).magnitude();
//	arr[1] = (aintersected - p).magnitude() / (aintersected - a).magnitude() * (aintersected - b).magnitude() / (c-b).magnitude();
//	arr[2] = (aintersected - p).magnitude() / (aintersected - a).magnitude() * (c - aintersected).magnitude() / (c - b).magnitude();
//	return arr;
//}

float* lt::InterpolationTriangle(Vector2<float> p, Vector2<float> a, Vector2<float> b, Vector2<float> c) {
	float arr[3];
	arr[1] = ((p.x - a.x)*(c.y - a.y) - (c.x - a.x) * (p.y - a.y)) / ((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y));
	arr[2] = ((p.x - a.x)*(b.y - a.y) - (b.x - a.x) * (p.y - a.y)) / ((c.x - a.x) * (b.y - a.y) - (b.x - a.x) * (c.y - a.y));
	arr[0] = 1 - arr[1] - arr[2];
	return arr;
}