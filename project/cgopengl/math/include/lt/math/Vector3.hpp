#ifndef _Vector3_H
#define _Vector3_H
namespace lt {
	template<class T>
	struct Vector2;
	template<class T>
	struct Vector3 {
		union
		{
			struct { T x, y, z; };
			struct { T r, g, b; };
			struct { T s, t, p; };
		};
		Vector3() :x(0), y(0), z(0) {}
		Vector3(T _x, T _y, T _z):x(_x), y(_y), z(_z){}
		Vector3 operator- (const Vector3& _v) {
			return Vector3(x-_v.x,y-_v.y,z-_v.z);
		}
		Vector3 operator+ (const Vector3& _v) {
			return Vector3(x + _v.x, y + _v.y, z + _v.z);
		}
		Vector3 operator* (const T _k) {
			return Vector3(x * _k, y  * _k, z  * _k);
		}
		Vector3 operator= (const Vector3& _v) {
			x = _v.x, y = _v.y,z =  _v.z;
			return *this;
		}
		operator Vector2<T>() const {
			return Vector2<T>(x, y);
		}

		T Dot(const Vector3& _v) {
			return x * _v.x+ y * _v.y+ z * _v.z;
		}
		Vector3 Cross(const Vector3& _v) {
			return Vector3(0, 0, 0);
		}
	};
}
#endif