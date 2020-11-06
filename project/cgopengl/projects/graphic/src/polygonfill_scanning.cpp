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

#include "lt/geometry/intersected.hpp"
#include"polygonfill_scanning.hpp"
using namespace std;
inline bool cmp(lt::Vector2<float> a, lt::Vector2<float> b) {
	return a.x < b.x;
}
lt::polygonfill_scanning::polygonfill_scanning(int _size, lt::Vector2<int>* _verticle, lt::Vector3<float>* _color) {
	size = _size;
	verticle = _verticle;
	color = _color;
};
lt::polygonfill_scanning::~polygonfill_scanning() {
};
void lt::polygonfill_scanning::Init() {
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	int minx = verticle[0].x, maxx = verticle[0].x, miny = verticle[0].y, maxy = verticle[0].y;
	for (int i = 0; i < size; i++) {
		minx = min(minx, verticle[i].x);
		maxx = max(maxx, verticle[i].x);
		miny = min(miny, verticle[i].y);
		maxy = max(maxy, verticle[i].y);
	}
	int nm = (maxx - minx + 1) * (maxy - miny + 1);
	lt::Vector3 <float>* v;
	v = (lt::Vector3 <float>*)malloc(sizeof(lt::Vector3 <float>) * nm * 2);

	count = 0;

	lt::Vector2<float>* intersected  = (lt::Vector2 <float>*)malloc(sizeof(lt::Vector2 <float>) * size);
	for (int i = miny; i <= maxy; i++) {
		lt::Vector2<float> scanninglinea = lt::Vector2<float>(minx,i);
		lt::Vector2<float> scanninglineb = lt::Vector2<float>(maxx, i);
		int intersectednums = 0;
		for (int j = 0; j < size; j++) {
			lt::Vector2<float> a = lt::Vector2<float>(verticle[(size + j - 1)%size].x, verticle[(size + j - 1) % size].y);
			lt::Vector2<float> b = lt::Vector2<float>(verticle[j].x, verticle[j].y);
			if (lt::IsLineIntersected(scanninglinea, scanninglineb, a, b)) {
				intersected[intersectednums] = PointLineIntersected(scanninglinea, scanninglineb, a, b);
				intersectednums++;
			}
		}
		sort(intersected, intersected + intersectednums, cmp);
		for (int k = 1; k < intersectednums; k++, k++) {
			for (int kk = intersected[k - 1].x; kk <= intersected[k].x; kk++) {
				v[count * 2] = lt::Vector3<float>(kk,i,0.0f);
				v[count * 2 + 1] = lt::Vector3<float>(1.0f, 0.0f, 0.0f);
				count++;
			}
		}
	}

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(lt::Vector3 <float>) * count * 2, v, GL_STATIC_DRAW);

	free(intersected);
	free(v);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// texture coord attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
};
void lt::polygonfill_scanning::Destroy() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}
void lt::polygonfill_scanning::Display() {
	glPointSize(1.0f);
	glBindVertexArray(VAO);
	glDrawArrays(GL_POINTS, 0, count);
};