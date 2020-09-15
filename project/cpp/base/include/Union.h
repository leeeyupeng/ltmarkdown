#include <iostream>
using namespace std;
struct  vector4
{
	union
	{
		struct {
			float r;
			float g;
			float b;
			float a;
		};
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
	};
};

void test() {
	vector4 v4;
	v4.x = 1.0f;
	v4.y = 2.0f;
	cout << v4.x << " " << v4.y << endl;
	cout << v4.r << " " << v4.g << endl;

	v4.r = 2.0f;
	v4.g = 1.0f;
	cout << v4.x << " " << v4.y << endl;
	cout << v4.r << " " << v4.g << endl;
}