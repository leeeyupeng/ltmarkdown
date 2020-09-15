#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//#include <learnopengl/filesystem.h>
#include <learnopengl/shader_m.h>
#include <learnopengl/camera.h>

#include <lt/math/math.hpp>
#include <lt/math/Vector2.hpp>
#include <lt/math/Vector3.hpp>

#include"ddaline.hpp"
lt::ddaline::ddaline(lt::Vector2<int> _a, lt::Vector3<float> _aColor, lt::Vector2<int> _b, lt::Vector3<float> _bColor) {
	a = _a;
	aColor = _aColor;
	b = _b;
	bColor = _bColor;
};
lt::ddaline::~ddaline() {
};
void lt::ddaline::Init() {
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	int dx = abs(b.x - a.x);
	int dy = abs(b.y - a.y);
	count = (dx >= dy ? dx : dy) + 1;

	lt::Vector3 <float>* v;
	v = (lt::Vector3 <float>*)malloc(sizeof(lt::Vector3 <float>) * count * 2);
	v[0] = lt::Vector3 <float>(a.x, a.y, 0.0f);
	v[1] = aColor;

	float dxx,dyy;
	if (dx > dy) {
		dxx = (b.x - a.x) > 0 ? 1 : -1;
		dyy = 1.0f * (b.y - a.y) / dx;
	}
	else
	{
		dxx = 1.0f * (b.x - a.x) / dy;
		dyy = (b.y - a.y) > 0 ? 1 : -1;
	}
	float x = a.x, y = a.y;
	for (int i = 0; i < count; i++) {
		v[i * 2] = lt::Vector3 <float>(lt::round(x),lt::round(y), 0.0f);
		v[i * 2 + 1] = aColor * (1.0f - 1.0f * i / count) + bColor * (1.0f *  i / count);
		x += dxx, y += dyy;
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
void lt::ddaline::Destroy() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}
void lt::ddaline::Display() {
	glPointSize(1.0f);
	glBindVertexArray(VAO);
	glDrawArrays(GL_POINTS, 0, count);
};