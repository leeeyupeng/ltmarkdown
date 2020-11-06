#include"lt/math/Vector2.hpp"
#include"lt/math/Vector3.hpp"
#include"lt/geometry/intersected.hpp"
using namespace lt;

bool lt::IsLineIntersected(Vector2<float> a1, Vector2<float> b1, Vector2<float> a2, Vector2<float> b2) {
	Vector2<float> a1b1 = b1 - a1;
	Vector2<float> a2b2 = b2 - a2;
	Vector2<float> a2a1 = a1 - a2;
	Vector2<float> a1a2 = a2 - a1;
	if (a1b1.Cross(a2b2) == 0) { return false; }
	float u = (a2b2.x * a2a1.y - a2a1.x * a2b2.y) / (a1b1.x * a2b2.y - a2b2.x * a1b1.y);
	float v = (a1b1.x * a1a2.y - a1a2.x * a1b1.y) / (a2b2.x * a1b1.y - a1b1.x * a2b2.y);
	return u >= 0 && u <= 1 && v >= 0 && v <= 1;
}

Vector2<float> lt::PointLineIntersected(Vector2<float> a1, Vector2<float> b1, Vector2<float> a2, Vector2<float> b2) {
	Vector2<float> a1b1 = b1 - a1;
	Vector2<float> a2b2 = b2 - a2;
	Vector2<float> a2a1 = a1 - a2;
	Vector2<float> a1a2 = a2 - a1;
	float u = (a2b2.x * a2a1.y - a2a1.x * a2b2.y) / (a1b1.x * a2b2.y - a2b2.x * a1b1.y);
	return a1 + a1b1 * u;
}
inline bool lt::IsPointInTriangle(Vector3<float> p, Vector3<float> a, Vector3<float> b, Vector3<float> c) {
	Vector2<float> ap = p - a;
	Vector2<float> ab = b - a;
	Vector2<float> ac = c - a;
	float u = 0, v = 0;
	u = (ap.x * ac.y - ac.x*ap.y) / (ab.x * ac.y - ac.x * ab.y);
	v = (ap.x * ab.y - ab.x*ap.y) / (ac.x * ab.y - ab.x * ac.y);
	return u >= 0 && v >= 0 && u + v <= 1;
}
inline bool lt::IsPointInFan(Vector2<float> p, Vector2<float> a, Vector2<float> b, Vector2<float> c) {
	Vector2<float> ap = p - a;
	Vector2<float> ab = b - a;
	Vector2<float> ac = c - a;
	if (ap.x * ap.x + ap.y * ap.y > ab.x * ab.x + ab.y * ab.y) { return false; }
	float u = 0, v = 0;
	u = (ap.x * ac.y - ac.x*ap.y) / (ab.x * ac.y - ac.x * ab.y);
	v = (ap.x * ab.y - ab.x*ap.y) / (ac.x * ab.y - ab.x * ac.y);
	return u >= 0 && v >= 0;
}