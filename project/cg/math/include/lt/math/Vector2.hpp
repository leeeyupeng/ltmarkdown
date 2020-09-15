#ifndef _Vector2_H
#define _Vector2_H
#include<cmath>
namespace lt {
	template<class T>
	struct Vector3;
	template<class T>
	struct Vector2 {
		union
		{
			struct { T x, y; };
		};
		Vector2() :x(0), y(0){}
		Vector2(T _x, T _y):x(_x), y(_y){}
		Vector2 operator- (const Vector2& _v) {
			return Vector2(x-_v.x,y-_v.y);
		}
		Vector2 operator+ (const Vector2& _v) {
			return Vector2(x + _v.x, y + _v.y);
		}
		Vector2 operator* (const T _k) {
			return Vector2(x * _k, y  * _k);
		}
		bool operator== (const Vector2& _v) {
			return x == _v.x && y == _v.y;
		}
		operator Vector3<T>() const {
			return Vector3<T>(x, y,0);
		}
		T Dot(const Vector2& _v) {
			return x * _v.x+ y * _v.y;
		}
		T Cross(const Vector2& _v) {
			return x*_v.y-_v.x * y;
		}
		T sqrMagnitude() {
			return x * x + y * y;
		}
		T magnitude() {
			return sqrt(x * x + y * y);
		}
	};
}
#endif