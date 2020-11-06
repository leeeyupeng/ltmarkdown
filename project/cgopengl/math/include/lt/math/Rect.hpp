#ifndef _Rect_H
#define _Rect_H
#include <iostream>
namespace lt {
	template<class T>
	struct Rect {
		union
		{
			struct { T x, y, width, height; };
		};
		Rect() :x(0), y(0), width(0),height(0){}
		Rect(T _x, T _y,T _width,T _height) :x(_x), y(_y), width(_width), height(_height) {}
	};
}
#endif