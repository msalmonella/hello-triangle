#include "../include/glad/glad.h"
#include "input.hpp"
#include "config/config.hpp"
#include "engine/window.hpp"
#include "engine/engine.hpp"
#include <GLFW/glfw3.h>
#include <iostream>



// Callback function to handle window resizing
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
	std::cout << Config::WINDOW_HEIGHT << std::endl;
	std::cout << Config::WINDOW_WIDTH << std::endl;
	// 1. Initialize GLFW
	if (!glfwInit()) {
		std::cout << "Failed to initialize GLFW" << std::endl;
		return -1;
	}

	// 2. Configure GLFW for OpenGL 3.3 Core Profile
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Required for macOS
#endif

	// 3. Create the Window Object
	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL 3.3 Window", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// 4. Register the resize callback
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// 5. Load OpenGL function pointers using GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// 6. The Main Render Loop
	while (!glfwWindowShouldClose(window)) {
		// Input processing can go here
		Input::process(window);

		// Render commands
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // Set a dark teal background
		glClear(GL_COLOR_BUFFER_BIT);

		// Swap buffers and poll window events
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// 7. Clean up resources
	glfwTerminate();
	return 0;
}

