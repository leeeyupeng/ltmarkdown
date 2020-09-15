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
#include"midpointcircle.hpp"
lt::midpointcircle::midpointcircle(lt::Vector2<int> _center, int _radiu) {
	center = _center;
	radiu = _radiu;
};
lt::midpointcircle::~midpointcircle() {
};
void lt::midpointcircle::circlepoint(int  x, int y) {
	v[count * 2] = lt::Vector3 <float>(x, y, 0.0f);
	v[count * 2 + 1] = lt::Vector3<float>(rand() % 100 / 100.0f, rand() % 100 / 100.0f, rand() % 100 / 100.0f);
	count++;
	v[count * 2] = lt::Vector3 <float>(y, x, 0.0f);
	v[count * 2 + 1] = lt::Vector3<float>(rand() % 100 / 100.0f, rand() % 100 / 100.0f, rand() % 100 / 100.0f);
	count++;
	v[count * 2] = lt::Vector3 <float>(x, -y, 0.0f);
	v[count * 2 + 1] = lt::Vector3<float>(rand() % 100 / 100.0f, rand() % 100 / 100.0f, rand() % 100 / 100.0f);
	count++;
	v[count * 2] = lt::Vector3 <float>(-y, x, 0.0f);
	v[count * 2 + 1] = lt::Vector3<float>(rand() % 100 / 100.0f, rand() % 100 / 100.0f, rand() % 100 / 100.0f);
	count++;
	v[count * 2] = lt::Vector3 <float>(-x, y, 0.0f);
	v[count * 2 + 1] = lt::Vector3<float>(rand() % 100 / 100.0f, rand() % 100 / 100.0f, rand() % 100 / 100.0f);
	count++;
	v[count * 2] = lt::Vector3 <float>(y, -x, 0.0f);
	v[count * 2 + 1] = lt::Vector3<float>(rand() % 100 / 100.0f, rand() % 100 / 100.0f, rand() % 100 / 100.0f);
	count++;
	v[count * 2] = lt::Vector3 <float>(-x, -y, 0.0f);
	v[count * 2 + 1] = lt::Vector3<float>(rand() % 100 / 100.0f, rand() % 100 / 100.0f, rand() % 100 / 100.0f);
	count++;
	v[count * 2] = lt::Vector3 <float>(-y, -x, 0.0f);
	v[count * 2 + 1] = lt::Vector3<float>(rand() % 100 / 100.0f, rand() % 100 / 100.0f, rand() % 100 / 100.0f);
	count++;
}
void lt::midpointcircle::Init() {
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	count = 0;

	v = (lt::Vector3 <float>*)malloc(sizeof(lt::Vector3 <float>) * radiu * 8 * 2);

	int x = 0, y = radiu;
	circlepoint(x,y);
	float d = 1.25 - radiu;
	while (x <= y) {
		if (d < 0) { d += 2 * x + 3; }
		else { y--; d += 2 * (x - y) + 5; }
		x++;
		circlepoint(x, y);
	}
	for (int i = 0; i < count; i++) {
		v[i * 2] = v[i * 2] + lt::Vector3 <float>(center.x,center.y,0.0f);
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
void lt::midpointcircle::Destroy() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}
void lt::midpointcircle::Display() {
	glPointSize(1.0f);
	glBindVertexArray(VAO);
	glDrawArrays(GL_POINTS, 0, count);
};