// Include GLFW
#include <GLFW/glfw3.h>
extern GLFWwindow* window; // The "extern" keyword here is to access the variable "window" declared in tutorialXXX.cpp. This is a hack to keep the tutorials simple. Please avoid this.

						   // Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
using namespace glm;

#include "controls.h"

glm::mat4 ViewMatrix;
glm::mat4 ProjectionMatrix;

glm::mat4 getViewMatrix() {
	return ViewMatrix;
}
glm::mat4 getProjectionMatrix() {
	return ProjectionMatrix;
}

float camInitialFoV = 45.0f;
float camSpeed = 3.0f;

float nearPlane = 0.1f;
float farPlane = 100.0f;

glm::vec3 camPosition = glm::vec3(10.0f, 0.0f, -5.0f);
glm::vec3 cameraTarget = glm::vec3(10.0f, 0.0f, 10.0f);
glm::vec3 cameraDirection = glm::normalize(camPosition - cameraTarget);
glm::vec3 cameraRight = glm::normalize(glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), cameraDirection));
glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);

void computeMatricesFromInputs(GLFWwindow* window, float deltaTime) {

	//===================TRANSLATE CAMERA====================//
	// Move forward
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
		camPosition += cameraDirection * deltaTime * camSpeed;
	}
	// Move backward
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
		camPosition -= cameraDirection * deltaTime * camSpeed;
	}
	// Strafe right
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
		camPosition -= cameraRight * deltaTime * camSpeed;
	}
	// Strafe left
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
		camPosition += cameraRight * deltaTime * camSpeed;
	}
	// Up
	if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS) {
		camPosition += cameraUp * deltaTime * camSpeed;
	}
	// Down
	if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS) {
		camPosition -= cameraUp * deltaTime * camSpeed;
	}
	//===================ROTATE CAMERA=====================//
	//Rotate around right
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		cameraDirection = glm::rotate(cameraDirection, glm::radians(-0.9f), cameraRight);
		cameraUp = glm::rotate(cameraUp, glm::radians(-0.9f), cameraRight);
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		cameraDirection = glm::rotate(cameraDirection, glm::radians(0.9f), cameraRight);
		cameraUp = glm::rotate(cameraUp, glm::radians(0.9f), cameraRight);
	}
	//Rotate around up
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		cameraDirection = glm::rotate(cameraDirection, glm::radians(0.9f), cameraUp);
		cameraRight = glm::rotate(cameraRight, glm::radians(0.9f), cameraUp);
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		cameraDirection = glm::rotate(cameraDirection, glm::radians(-0.9f), cameraUp);
		cameraRight = glm::rotate(cameraRight, glm::radians(-0.9f), cameraUp);
	}
	//Rotate around front
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
		cameraUp = glm::rotate(cameraUp, glm::radians(0.9f), cameraDirection);
		cameraRight = glm::rotate(cameraRight, glm::radians(0.9f), cameraDirection);
	}
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
		cameraUp = glm::rotate(cameraUp, glm::radians(-0.9f), cameraDirection);
		cameraRight = glm::rotate(cameraRight, glm::radians(-0.9f), cameraDirection);
	}

	float FoV = camInitialFoV;
	ProjectionMatrix = glm::perspective(FoV, 4.0f / 3.0f, nearPlane, farPlane);
	// Camera matrix
	ViewMatrix = glm::lookAt(
		camPosition,					// Camera is here
		camPosition + cameraDirection,	// and looks here : at the same position, plus "direction"
		cameraUp						// Head is up (set to 0,-1,0 to look upside-down)
	);
}