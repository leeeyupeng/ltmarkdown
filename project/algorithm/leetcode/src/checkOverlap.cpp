#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
private:
	bool inbox(int x, int y, int x1, int y1, int x2, int y2) {
		return x >= x1 && x <= x2 && y >= y1 && y <= y2;
	}
	bool incircle(int radius, int x_center, int y_center, int x, int y) {
		return (x - x_center) * (x - x_center) + (y - y_center) * (y - y_center) <= radius * radius;
	}
	bool crosscirclelinex(int radius, int x_center, int y_center, int x, int y1, int y2) {
		return (abs(x - x_center) <= radius) &&  y_center >= y1 && y_center <= y2;
	}
	bool crosscircleliney(int radius, int x_center, int y_center, int x1, int x2, int y) {
		return (abs(y - y_center) <= radius) && x_center >= x1 && x_center <= x2;
	}
public:
	bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
		if (inbox(x_center, y_center, x1, y1, x2, y2)) { return true; }
		if (incircle(radius, x_center, y_center,x1,y1)) { return true; }
		if (incircle(radius, x_center, y_center, x1, y2)) { return true; }
		if (incircle(radius, x_center, y_center, x2, y1)) { return true; }
		if (incircle(radius, x_center, y_center, x2, y2)) { return true; }
		if (inbox(x_center + radius, y_center, x1, y1, x2, y2)) { return true; }
		if (inbox(x_center - radius, y_center, x1, y1, x2, y2)) { return true; }
		if (inbox(x_center, y_center + radius, x1, y1, x2, y2)) { return true; }
		if (inbox(x_center, y_center - radius, x1, y1, x2, y2)) { return true; }
		if (crosscirclelinex(radius, x_center, y_center, x1, y1, y2)) {return true;}
		if (crosscirclelinex(radius, x_center, y_center, x2, y1, y2)) { return true; }
		if (crosscircleliney(radius, x_center, y_center, x1, x2, y1)) { return true; }
		if (crosscircleliney(radius, x_center, y_center, x1, x2, y2)) { return true; }
		return false;
	}
};