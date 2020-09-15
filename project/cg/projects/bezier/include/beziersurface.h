#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <learnopengl/filesystem.h>
#include <learnopengl/shader_m.h>
#include <learnopengl/camera.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
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

#define NUMPOINTU 50
#define NUMPOINTV 50

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
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "beziersurface", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

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
	float vertices_p[4 * 4 * 6];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			float x = i * 2 + (rand() % 100) / 100.0f;
			float y = j * 2 + 10 * (rand() % 100) / 100.0f;
			//float x = i * 2;
			//float y = j * 2;
			float z = j * 2;// 30 * (rand() % 100) / 100.0f;
			vertices_p[(i * 4 + j) * 6 + 0] = x;
			vertices_p[(i * 4 + j) * 6 + 1] = y;
			vertices_p[(i * 4 + j) * 6 + 2] = z;
			vertices_p[(i * 4 + j) * 6 + 3] = (i * j )/ 8 +  0.5f * (rand() % 100) / 100.0f;
			vertices_p[(i * 4 + j) * 6 + 4] = (i * j) / 8 + 0.5f *(rand() % 100) / 100.0f;
			vertices_p[(i * 4 + j) * 6 + 5] = (i * j) / 8 + 0.5f *(rand() % 100) / 100.0f;
		}
	}

	float vertices[NUMPOINTU *NUMPOINTV * 6]{0};
	float verticestemp[4 * 6];
	for (int i = 0; i < NUMPOINTU; i++) {
		float u = i * 1.0f / (NUMPOINTU - 1);
		for (int ii = 0; ii < 4; ii++) {
			for (int k = 0; k < 6; k++) {
				verticestemp[ii * 6 + k] = vertices_p[(ii * 4 + 0) * 6 + k] * pow(1.0f - u, 3);
				verticestemp[ii * 6 + k] += 3 * vertices_p[(ii * 4+1) * 6 + k] * u * pow(1.0f - u, 2);
				verticestemp[ii * 6 + k] += 3 * vertices_p[(ii * 4+2) * 6 + k] * pow(u, 2) * (1.0f - u);
				verticestemp[ii * 6 + k] += vertices_p[(ii * 4+3) * 6 + k] * pow(u, 3);
			}
		}
		for (int j = 0; j < NUMPOINTV; j++) {
			float v = j * 1.0f / (NUMPOINTV - 1);
			for (int k = 0; k < 6; k++) {
				vertices[(i * NUMPOINTU + j) * 6 + k] = verticestemp[0 * 6 + k] * pow(1.0f - v, 3);
				vertices[(i * NUMPOINTU + j) * 6 + k] += 3 * verticestemp[1 * 6 + k] * v * pow(1.0f - v, 2);
				vertices[(i * NUMPOINTU + j) * 6 + k] += 3 * verticestemp[2 * 6 + k] * pow(v, 2) * (1.0f - v);
				vertices[(i * NUMPOINTU + j) * 6 + k] += verticestemp[3 * 6 + k] * pow(v, 3);
			}
		}
	}

	unsigned int indices[((NUMPOINTU - 1) *(NUMPOINTV)  + (NUMPOINTU) *(NUMPOINTV - 1)) * 2]{ 0 };
	int index = 0;
	for (int i = 0; i < NUMPOINTU; i++) {
		for (int j = 0; j < NUMPOINTV - 1; j++) {
			indices[index] = i * NUMPOINTU + j;
			indices[index+1] = i * NUMPOINTU + j + 1;
			index += 2;
		}
	}
	for (int i = 0; i < NUMPOINTU - 1; i++) {
		for (int j = 0; j < NUMPOINTV; j++) {
			indices[index] = i * NUMPOINTU + j;
			indices[index + 1] = (i + 1) * NUMPOINTU + j;
			index += 2;
		}
	}

	unsigned int VBO_p, VAO_p;
	glGenVertexArrays(1, &VAO_p);
	glGenBuffers(1, &VBO_p);

	glBindVertexArray(VAO_p);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_p);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_p), vertices_p, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// texture coord attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	
    unsigned int VBO, VAO,EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

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

		glm::mat4 model = glm::mat4(1.0f);

		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));

		//float angle = 60.0f;
		//model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.0f, 0.0f));

		model = glm::translate(model, glm::vec3(-4.0f, -4.0f, 0.0f));
		
		//model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
		ourShader.setMat4("model", model);

		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		// render container
		glBindVertexArray(VAO_p);
		int nums = sizeof(vertices_p) / sizeof(float) / 6;
		glDrawArrays(GL_LINE_STRIP, 0, nums);
		//glDrawArrays(GL_LINE_STRIP, 0, nums);

		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        // render container
        glBindVertexArray(VAO);

		glDrawElements(GL_LINES, ((NUMPOINTU - 1) *(NUMPOINTV)+(NUMPOINTU) *(NUMPOINTV - 1)) * 2, GL_UNSIGNED_INT,0);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

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