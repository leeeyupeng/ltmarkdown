#include <iostream>
using namespace std;
struct  vector4
{
	union u4
	{
		struct c4{
			float r;
			float g;
			float b;
			float a;
		}c;
		struct v4
		{
			float x;
			float y;
			float z;
			float w;
		}v;
	}u;
};

void test() {
	vector4 v4;

	v4.u.v.x = 1.0f;
	v4.u.v.y = 2.0f;
	cout << v4.u.v.x << " " << v4.u.v.y << endl;
	cout << v4.u.c.r << " " << v4.u.c.g << endl;

	v4.u.c.r = 2.0f;
	v4.u.c.g = 1.0f;
	cout << v4.u.v.x << " " << v4.u.v.y << endl;
	cout << v4.u.c.r << " " << v4.u.c.g << endl;
}