#include <iostream>
#include"maths/vec2.h"
using namespace std;

vec2::vec2(float x, float y) :x(x), y(y) { }
vec2 vec2::operator=(const vec2& a) {
	this->x = a.x;
	this->y = a.y;
	return *this;
}
vec2 vec2::operator+(const vec2& a) {
	return { this->x + a.x, this->y + a.y };
}
vec2 vec2::operator-(const vec2& a) {
	return { this->x - a.x, this->y - a.y };
}
vec2 vec2::operator*(const float scalar) {
	return { this->x * scalar, this->y * scalar };
}
vec2 vec2::operator*(const vec2& a) {
	return { this->x * a.x, this->y*a.y };
}