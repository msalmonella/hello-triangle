#include "../include/glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

// Callback function to handle window resizing
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main(){
	std::cout << "Hello World" << std::endl;
}
