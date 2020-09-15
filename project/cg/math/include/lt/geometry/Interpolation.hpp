#ifndef _INTERPOLATION_H
#define _INTERPOLATION_H
namespace lt {
	template<class T>
	struct Vector2;
	template<class T>
	struct Vector3;

	float* InterpolationTriangle(Vector2<float> p, Vector2<float> a, Vector2<float> b, Vector2<float> c);
}
#endif