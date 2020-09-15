#ifndef _INTERSECTED_H
#define _INTERSECTED_H
namespace lt {
	template<class T>
	struct Vector2;
	template<class T>
	struct Vector3;

	bool IsLineIntersected(Vector2<float> a1, Vector2<float> b1, Vector2<float> a2, Vector2<float> b2);
	Vector2<float> PointLineIntersected(Vector2<float> a1, Vector2<float> b1, Vector2<float> a2, Vector2<float> b2);
	inline bool IsPointInTriangle(Vector3<float> p, Vector3<float> a, Vector3<float> b, Vector3<float> c);
	inline bool IsPointInFan(Vector2<float> p, Vector2<float> a, Vector2<float> b, Vector2<float> c);
}
#endif