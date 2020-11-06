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

#include"drawpoint.hpp"
lt::drawpoint::drawpoint(lt::Vector2<float> _a, lt::Vector3<float> _aColor) {
	a = _a;
	aColor = _aColor;
};
lt::drawpoint::~drawpoint() {
};
void lt::drawpoint::Init() {
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	lt::Vector3<float> v[2];
	v[0] = a;
	v[0].z = 0.0f;
	v[1] = aColor;

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(lt::Vector3 <float>) * 2, v, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// texture coord attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
};
void lt::drawpoint::Destroy() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}
void lt::drawpoint::Display() {
	glPointSize(5.0f);
	glBindVertexArray(VAO);
	glDrawArrays(GL_POINTS, 0, 1);
};