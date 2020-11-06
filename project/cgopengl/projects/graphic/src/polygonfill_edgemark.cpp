#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//#include <learnopengl/filesystem.h>
#include <learnopengl/shader_m.h>
#include <learnopengl/camera.h>

#include <lt/math/Vector2.hpp>
#include <lt/math/Vector3.hpp>

#include <iostream>
#include <algorithm>

#include"polygonfill_edgemark.hpp"
using namespace std;

inline bool cmp(lt::Vector2<float> a, lt::Vector2<float> b) {
	return a.x < b.x;
}
inline void minpointlinefill(int n, int m, bool* mark, lt::Vector3<float>* markcolor, lt::Vector2<int> pointa, lt::Vector2<int> pointb) {
	int x = pointa.x, y = pointa.y;
	mark[x*m + y] = true;
	int a = pointa.y - pointb.y, b = pointb.x - pointa.x;
	int d1, d2, d, dx, dy;
	dx = b > 0 ? 1 : -1;
	dy = a < 0 ? 1 : -1;
	if (abs(pointb.x - pointa.x) > abs(pointa.y - pointb.y)) {
		if (a <= 0 && b >= 0) {
			d1 = 2 * a, d2 = 2 * (a + b);
			d = 2 * a + b;
			while (x < pointb.x) {
				if (d < 0) {
					y += dy; d += d2; 
				}
				else { d += d1; }
				x += dx;
				mark[x*m + y] = true;
			}
		}
		else if (a <= 0 && b < 0) {
			d1 = 2 * (-a), d2 = 2 * (-a + b);
			d = 2 * (-a) + b;
			while (x > pointb.x) {
				if (d > 0) {
					y += dy; d += d2; 
				}
				else { d += d1; }
				x += dx;
				mark[x*m + y] = true;
			}
		}
		else if (a > 0 && b >= 0) {
			d1 = 2 * a, d2 = 2 * (a - b);
			d = 2 * a - b;
			while (x < pointb.x) {
				if (d > 0) {
					y += dy; d += d2; 
				}
				else { d += d1; }
				x += dx;
				mark[x*m + y] = true;
			}
		}
		else if (a > 0 && b < 0) {
			d1 = 2 * (-a), d2 = 2 * (-a - b);
			d = 2 * (-a) - b;
			while (x > pointb.x) {
				if (d < 0) {
					y += dy; d += d2;					
				}
				else { d += d1; }
				x += dx;
				mark[x*m + y] = true;
			}
		}
	}
	else
	{
		if (a <= 0 && b >= 0) {
			d1 = 2 * b, d2 = 2 * (b + a);
			d = 2 * b + a;
			while (y < pointb.y) {
				if (d > 0) {
					x += dx; d += d2; mark[x*m + y] = true;
				}
				else { d += d1; }
				y += dy;
			}
		}
		else if (a <= 0 && b < 0) {
			d1 = 2 * b, d2 = 2 * (b - a);
			d = 2 * b - a;
			while (y < pointb.y) {
				if (d < 0) {
					x += dx; d += d2; mark[x*m + y] = true;
				}
				else { d += d1; }
				y += dy;
			}
		}
		else if (a > 0 && b >= 0) {
			d1 = 2 * -b, d2 = 2 * (-b + a);
			d = 2 * -b + a;
			while (y > pointb.y) {
				if (d < 0) {
					x += dx; d += d2; mark[x*m + y] = true;
				}
				else { d += d1; }
				y += dy;
			}
		}
		else if (a > 0 && b < 0) {
			d1 = 2 * (-b), d2 = 2 * (-b - a);
			d = 2 * (-b) - a;
			while (y > pointb.y) {
				if (d > 0) {
					x += dx; d += d2; mark[x*m + y] = true;
				}
				else { d += d1; }
				y += dy;
			}
		}
	}
}
lt::polygonfill_edgemark::polygonfill_edgemark(int _size, lt::Vector2<int>* _verticle, lt::Vector3<float>* _color) {
	size = _size;
	verticle = _verticle;
	color = _color;
};
lt::polygonfill_edgemark::~polygonfill_edgemark() {
};
void lt::polygonfill_edgemark::Init() {
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	int minx = verticle[0].x, maxx = verticle[0].x, miny = verticle[0].y, maxy = verticle[0].y;
	for (int i = 0; i < size; i++) {
		minx = min(minx, verticle[i].x);
		maxx = max(maxx, verticle[i].x);
		miny = min(miny, verticle[i].y);
		maxy = max(maxy, verticle[i].y);
	}
	int n = (maxx - minx + 1);
	int m = (maxy - miny + 1);
	int nm = (maxx - minx + 1) * (maxy - miny + 1);

	bool* mark;
	mark = (bool*)malloc(sizeof(bool) * nm);
	memset(mark,0, sizeof(bool) * nm);
	lt::Vector3 <float>* markcolor;
	markcolor = (lt::Vector3 <float>*)malloc(sizeof(lt::Vector3 <float>) * nm);
	for (int i = 0; i < size; i++) {
		lt::Vector2<float> a = lt::Vector2<float>(verticle[(size + i - 1) % size].x, verticle[(size + i - 1) % size].y);
		lt::Vector2<float> b = lt::Vector2<float>(verticle[i].x, verticle[i].y);

		minpointlinefill(n,m,mark,markcolor, verticle[(size + i - 1) % size] - lt::Vector2<int>(minx,miny), verticle[i] - lt::Vector2<int>(minx, miny));
	}

	lt::Vector3 <float>* v;
	v = (lt::Vector3 <float>*)malloc(sizeof(lt::Vector3 <float>) * nm * 2);

	count = 0;

	bool inside = false;
	for (int i = 0; i < n; i++) {
		inside = false;
		for (int j = 0; j < m; j++) {
			if (mark[i * m + j]) { inside = !inside; }
			mark[i * m + j] = mark[i * m + j] || inside;
		}
		if (inside == true)
		{
			for (int j = m - 1; j > 0; j--) {
				if (mark[i * m + j-1]) {
					mark[i * m + j] = false;
				}
				else
				{
					break;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++){
			if(mark[i * m + j]){
				v[count * 2] = lt::Vector3<float>(i, j, 0.0f) + lt::Vector2<float>(minx, miny);
				v[count * 2 + 1] = lt::Vector3<float>(1.0f, 0.0f, 0.0f);
				count++;
			}
		}
	}

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(lt::Vector3 <float>) * count * 2, v, GL_STATIC_DRAW);

	free(mark);
	free(markcolor);
	free(v);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// texture coord attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
};
void lt::polygonfill_edgemark::Destroy() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}
void lt::polygonfill_edgemark::Display() {
	glPointSize(1.0f);
	glBindVertexArray(VAO);
	glDrawArrays(GL_POINTS, 0, count);
};