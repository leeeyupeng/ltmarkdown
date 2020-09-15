#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//#include <learnopengl/filesystem.h>
#include <learnopengl/shader_m.h>
#include <learnopengl/camera.h>

//#include <lt/math/math.hpp>
#include <lt/math/Vector2.hpp>
#include <lt/math/Vector3.hpp>

#include"drawpolygon.hpp"
lt::drawpolygon::drawpolygon(int _size, lt::Vector2<int>* _verticle, lt::Vector3<float>* _color) {
	size = _size;
	verticle = _verticle;
	color = _color;
};
lt::drawpolygon::~drawpolygon() {
};
void lt::drawpolygon::Init() {
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	count = size;
	lt::Vector3<float>* v;
	v = (lt::Vector3<float>*)malloc(sizeof(lt::Vector3<float>) * count * 2);
	for (int i = 0; i < count; i++) {
		v[i * 2] = lt::Vector3<float>(verticle[i].x,verticle[i].y,0.0f);
		v[i * 2 + 1] = color[i];
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
void lt::drawpolygon::Destroy() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}
void lt::drawpolygon::Display() {
	glPointSize(5.0f);
	glBindVertexArray(VAO);
	glDrawArrays(GL_LINE_LOOP, 0, count);
};