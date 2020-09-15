//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <stb_image.h>
//
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//#include <learnopengl/filesystem.h>
//#include <learnopengl/shader_m.h>
//#include <learnopengl/camera.h>
//
//#include <lt/math/Vector2.hpp>
//#include <lt/math/Vector3.hpp>
//
//#include <iostream>
//
////INCLUDE
//#include "drawpoint.hpp"
//#include"ddaline.hpp"
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow *window);
//
//// settings
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
//float lastX = SCR_WIDTH / 2.0f;
//float lastY = SCR_HEIGHT / 2.0f;
//bool firstMouse = true;
//
//
//// timing
//float deltaTime = 0.0f;	// time between current frame and last frame
//float lastFrame = 0.0f;
//
//int main()
//{
//	// glfw: initialize and configure
//	// ------------------------------
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//#ifdef __APPLE__
//	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
//#endif
//
//	// glfw window creation
//	// --------------------
//	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "geometry3", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//	// glad: load all OpenGL function pointers
//	// ---------------------------------------
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//
//	Shader ourShader("shaderpixel.vs", "shaderpixel.fs");
//	ourShader.use();
//	// set up vertex data (and buffer(s)) and configure vertex attributes
//	// ------------------------------------------------------------------
//
//	//INIT
//	//lt::midpointline mpl(lt::Vector2<int>(100,100), lt::Vector3<float>(1.0f, 0.0f,0.0f),
//	//	lt::Vector2<int>(700, 500),lt::Vector3<float>(0.0f, 1.0f, 0.0f));
//	lt::ddaline mpl1(lt::Vector2<int>(100,200), lt::Vector3<float>(1.0f, 0.0f,0.0f),
//		lt::Vector2<int>(700, 300),lt::Vector3<float>(0.0f, 1.0f, 0.0f));
//	lt::ddaline mpl2(lt::Vector2<int>(100, 300), lt::Vector3<float>(1.0f, 0.0f, 0.0f),
//		lt::Vector2<int>(700, 200), lt::Vector3<float>(0.0f, 1.0f, 0.0f));
//	lt::ddaline mpl3(lt::Vector2<int>(100, 100), lt::Vector3<float>(1.0f, 0.0f, 0.0f),
//		lt::Vector2<int>(200, 500), lt::Vector3<float>(0.0f, 1.0f, 0.0f));
//	lt::ddaline mpl4(lt::Vector2<int>(200, 100), lt::Vector3<float>(1.0f, 0.0f, 0.0f),
//		lt::Vector2<int>(100, 500), lt::Vector3<float>(0.0f, 1.0f, 0.0f));
//	lt::ddaline mpl5(lt::Vector2<int>(100, 500), lt::Vector3<float>(1.0f, 0.0f, 0.0f),
//		lt::Vector2<int>(200, 100), lt::Vector3<float>(0.0f, 1.0f, 0.0f));
//
//	mpl1.Init();
//	mpl2.Init();
//	mpl3.Init();
//	mpl4.Init();
//	mpl5.Init();
//
//	glPointSize(5.0f);
//	// render loop
//	// -----------
//	while (!glfwWindowShouldClose(window))
//	{
//		// per-frame time logic
//		// --------------------
//		float currentFrame = glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		// input
//		// -----
//		processInput(window);
//
//		// render
//		// ------
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		// render container
//
//
//		//DISPLAY
//		mpl1.Display();
//		mpl2.Display();
//		mpl3.Display();
//		mpl4.Display();
//		mpl5.Display();
//
//		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
//		// -------------------------------------------------------------------------------
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	// glfw: terminate, clearing all previously allocated GLFW resources.
//	// ------------------------------------------------------------------
//	glfwTerminate();
//	return 0;
//}
//
//// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
//// ---------------------------------------------------------------------------------------------------------
//void processInput(GLFWwindow *window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//}
//
//// glfw: whenever the window size changed (by OS or user resize) this callback function executes
//// ---------------------------------------------------------------------------------------------
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	// make sure the viewport matches the new window dimensions; note that width and 
//	// height will be significantly larger than specified on retina displays.
//	glViewport(0, 0, width, height);
//}
//
//// glfw: whenever the mouse moves, this callback is called
//// -------------------------------------------------------
//void mouse_callback(GLFWwindow* window, double xpos, double ypos)
//{
//}
//
//// glfw: whenever the mouse scroll wheel scrolls, this callback is called
//// ----------------------------------------------------------------------
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
//{
//}