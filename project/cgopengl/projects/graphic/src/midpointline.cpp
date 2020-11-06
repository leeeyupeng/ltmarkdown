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
#include"midpointline.hpp"
lt::midpointline::midpointline(lt::Vector2<int> _a, lt::Vector3<float> _aColor, lt::Vector2<int> _b, lt::Vector3<float> _bColor) {
	a = _a;
	aColor = _aColor;
	b = _b;
	bColor = _bColor;
};
lt::midpointline::~midpointline() {
};
void lt::midpointline::Init() {
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	int dx = abs(b.x - a.x);
	int dy = abs(b.y - a.y);
	count = (dx >= dy?dx : dy) + 1;

	lt::Vector3 <float>* v;
	v = (lt::Vector3 <float>*)malloc(sizeof(lt::Vector3 <float>) * count * 2);
	v[0] = lt::Vector3 <float>(a.x,a.y,0.0f);
	v[1] = aColor;

	if (dx >= dy) {
		int d = 2 * dy - dx;
		int d1 = 2 * dy;
		int d2 = 2 * (dy - dx);
		int x = a.x, y = a.y;
		int dxx = b.x - a.x >= 0?1:-1;
		int dyy = b.y - a.y >= 0 ? 1 : -1;
		while ((dxx == 1 && x < b.x) || (dxx == -1 && x > b.x)) {
			x+=dxx;
			if (d <= 0) {
				d += d1;
			}
			else {
				y += dyy; d += d2;
			}
			v[abs(x - a.x) * 2] = lt::Vector3 <float>(x, y, 0.0f);
			v[abs(x - a.x) * 2 + 1] = aColor * (1.0f - 1.0f * abs(x - a.x) / dx) + bColor * (1.0f * abs(x - a.x) / dx);
		}
	}
	else
	{
		int d = 2 * dx - dy;
		int d1 = 2 * dx;
		int d2 = 2 * (dx - dy);
		int x = a.x, y = a.y;
		int dxx = b.x - a.x > 0 ? 1 : -1;
		int dyy = b.y - a.y >= 0 ? 1 : -1;
		while ((dyy == 1 && y < b.y) || (dyy == -1 && y > b.y)) {
			y+=dyy;
			if (d <= 0) {
				d += d1;
			}
			else {
				x += dxx; d += d2;
			}
			v[abs(y - a.y) * 2] = lt::Vector3 <float>(x, y, 0.0f);
			v[abs(y - a.y) * 2 + 1] = aColor * (1.0f - 1.0f * abs(y - a.y) / dy) + bColor * (1.0f * abs(y - a.y) / dy);
		}
	}

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(lt::Vector3 <float>) * count * 2, v, GL_STATIC_DRAW);

	free(v);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// texture coord attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
};
void lt::midpointline::Destroy() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}
void lt::midpointline::Display() {
	glPointSize(1.0f);
	glBindVertexArray(VAO);
	glDrawArrays(GL_POINTS, 0, count);
};