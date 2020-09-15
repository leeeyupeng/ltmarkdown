#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <learnopengl/filesystem.h>
#include <learnopengl/shader_m.h>
#include <learnopengl/camera.h>


#include <lt/math/Vector3.hpp>
#include <lt/math/Vector2.hpp>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

// timing
float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;

bool IsPointInFan(lt::Vector2<float> p, lt::Vector2<float> a, lt::Vector2<float> b, lt::Vector2<float> c) {
	lt::Vector2<float> ap = p - a;
	lt::Vector2<float> ab = b - a;
	lt::Vector2<float> ac = c - a;
	if (ap.x * ap.x + ap.y * ap.y > ab.x * ab.x + ab.y * ab.y) { return false; }
	float u = 0, v = 0;
	u = (ap.x * ac.y - ac.x*ap.y) / (ab.x * ac.y - ac.x * ab.y);
	v = (ap.x * ab.y - ab.x*ap.y) / (ac.x * ab.y - ab.x * ac.y);
	return u >= 0 && v >= 0;
}

#define PNUMS 1000
int main_pro()
{
	// glfw: initialize and configure
	// ------------------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

	// glfw window creation
	// --------------------
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "pointinfan", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// build and compile our shader zprogram
	// ------------------------------------
	Shader ourShader("transform.vs", "transform.fs");

	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------

	int NFan;
	lt::Vector3<float> a = lt::Vector3<float>(0, -5.0f,-10.0f);
	lt::Vector3<float> b = lt::Vector3<float>(-5.0f, 0.0f,-10.0f);
	lt::Vector3<float> c = lt::Vector3<float>(5.0f, 0.0f,-10.0f);
	unsigned int VBO, VAO;
	{
		NFan = (c.x - b.x) / 0.2f;
		lt::Vector3<float>* v = (lt::Vector3<float>*)malloc(sizeof(lt::Vector3<float>) * (NFan + 1) * 2);
		v[0] = a;
		v[1] = lt::Vector3<float>(1.0f, 0.0f, 0.0f);
		lt::Vector3<float> vr = b-a;
		float sqrtradiu = (pow(vr.x,2)+pow(vr.y,2));
		float radiu = sqrtf(sqrtradiu);
		for (int i = 0; i < NFan; i++) {
			v[(i + 1) * 2].x = b.x + (c.x - b.x) * (i) / (NFan - 1);
			//v[(i + 1) * 2].x = a.x * (NFan - 1 - i) / (NFan - 1) + b.x * (i) / (NFan - 1);
			v[(i + 1) * 2].y = sqrtf(sqrtradiu - pow(v[(i + 1) * 2].x,2));
			v[(i + 1) * 2].z = 0.0f;
			v[(i + 1) * 2] = v[(i + 1) * 2] + a;

			v[(i + 1) * 2 + 1] = lt::Vector3<float>(rand() % 100 / 100.0f, rand() % 100 / 100.0f, rand() % 100 / 100.0f);
 		}
		v[3] = lt::Vector3<float>(0.0f, 1.0f, 0.0f);
		v[NFan * 2 + 1] = lt::Vector3<float>(0.0f, 0.0f, 1.0f);
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		int l = sizeof(lt::Vector3 <float>);
		glBufferData(GL_ARRAY_BUFFER, sizeof(lt::Vector3 <float>) * (NFan + 1) * 2, v, GL_STATIC_DRAW);

		// position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		// texture coord attribute
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		free(v);
	}

	unsigned int VBO2, VAO2;
	{
		lt::Vector3<float> v[PNUMS * 2];
		for (int i = 0; i < PNUMS; i++) {
			v[i * 2].x = rand() % 1000 / 100.0f - 5.0f;
			v[i * 2].y = rand() % 1000 / 100.0f - 5.0f;
			//v[i * 2].x = -5.0f;
			//v[i * 2].y = 5.0f;
			v[i * 2].z = -10.0f;
			bool isIn = IsPointInFan(v[i * 2], a, b, c);
			if (isIn) {
				v[i * 2 + 1].r = 1.0f;
				v[i * 2 + 1].g = 0.0f;
				v[i * 2 + 1].b = 0.0f;
			}
			else {
				v[i * 2 + 1].r = 0.0f;
				v[i * 2 + 1].g = 1.0f;
				v[i * 2 + 1].b = 0.0f;
			}
		}
		glGenVertexArrays(1, &VAO2);
		glGenBuffers(1, &VBO2);

		glBindVertexArray(VAO2);

		glBindBuffer(GL_ARRAY_BUFFER, VBO2);
		glBufferData(GL_ARRAY_BUFFER, sizeof(v), v, GL_STATIC_DRAW);

		// position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		// texture coord attribute
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
	}

	glPointSize(5.0f);
	// render loop
	// -----------
	while (!glfwWindowShouldClose(window))
	{
		// per-frame time logic
		// --------------------
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		// input
		// -----
		processInput(window);

		// render
		// ------
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// get matrix's uniform location and set matrix
		ourShader.use();
		// pass projection matrix to shader (note that in this case it could change every frame)
		glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
		ourShader.setMat4("projection", projection);

		// camera/view transformation
		glm::mat4 view = camera.GetViewMatrix();
		ourShader.setMat4("view", view);

		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		// render container


		{
			// calculate the model matrix for each object and pass it to shader before drawing
			glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
			//model = glm::translate(model, glm::vec3(0.0f,0.0f,0.0f));
			//float angle = 20.0f * i;
			//model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
			ourShader.setMat4("model", model);
		}
		{
			glBindVertexArray(VAO);
			glDrawArrays(GL_TRIANGLE_FAN, 0, NFan + 1);
		}

		{
			glBindVertexArray(VAO);
			glDrawArrays(GL_POINTS, 0, NFan + 1);
		}

		{
			glBindVertexArray(VAO2);
			glDrawArrays(GL_POINTS, 0, PNUMS);
		}


		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// optional: de-allocate all resources once they've outlived their purpose:
	// ------------------------------------------------------------------------
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	glDeleteVertexArrays(1, &VAO2);
	glDeleteBuffers(1, &VBO2);

	// glfw: terminate, clearing all previously allocated GLFW resources.
	// ------------------------------------------------------------------
	glfwTerminate();
	return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.ProcessKeyboard(FORWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.ProcessKeyboard(BACKWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.ProcessKeyboard(LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.ProcessKeyboard(RIGHT, deltaTime);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

	lastX = xpos;
	lastY = ypos;

	camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.ProcessMouseScroll(yoffset);
}