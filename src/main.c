/*
	Vulkan Context Experiments

	Written By: Ryan Smith
*/
#include <stdio.h>
#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"

#define WIDTH 1920
#define HEIGHT 1080

int main(int argc, char** argv)
{
	(void)argc;
	(void)argv;

	// GLFW: Initialize
	if (!glfwInit())
	{
		fprintf(stderr, "Unable to init GLFW.\n");
		return 1;
	}

	// GLFW: Vulkan
	if (!glfwVulkanSupported())
	{
		fprintf(stderr, "Vulkan is not supported");
		return 1;
	}
	PFN_vkCreateInstance pfnCreateInstance = (PFN_vkCreateInstance)
    glfwGetInstanceProcAddress(NULL, "vkCreateInstance");

	// GLFW: Create Window
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", NULL, NULL);
	if (!window)
	{
		fprintf(stderr, "Unable to create a GLFW window.\n");
		glfwTerminate();
		return 1;
	}

	// GLFW: Loop
	while (!glfwWindowShouldClose(window))
	{
		/* Events */
		glfwPollEvents();
		int escapeKeyState = glfwGetKey(window, GLFW_KEY_ESCAPE);
		if (escapeKeyState == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GLFW_TRUE);
		/* Rendering */
		glfwSwapBuffers(window);
	}

	// GLFW: Close
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
