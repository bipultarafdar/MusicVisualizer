//#ifndef TWEAKBAR_H
//#define TWEAKBAR_H
//
//#include <AntTweakBar.h>
//
//bool changeSpread = false;
//
//float bgColor[4] = { 1.0, 0.5, 0.0, 1.0 };
//float lightColor[4] = { 1.0,1.0,1.0,1.0 };
//float lightColorOff[4] = { 0.0, 0.0, 0.0, 0.0 };
//
//bool CCW = false;
//
//typedef enum { FILL, LINE, POINT } MESH_TYPE;
//MESH_TYPE m_currentMesh;
//
//typedef enum { CUBE, CYBORG, ROCK, TWO_CUBES } MODEL_TYPE;
//MODEL_TYPE m_currentModel;
//
//bool dirLightEnable = true;
//bool ptLightEnable = true;
////bool glLightEnable = ON;
//bool isTexEnabled = true;
//bool isNorEnabled = true;
//
//void callATB(TwBar* bar, GLFWwindow* window);
//
//inline void TwEventMouseButtonGLFW3(GLFWwindow* /*window*/, int button, int action, int /*mods*/)
//{
//	TwEventMouseButtonGLFW(button, action);
//}
//inline void TwEventMousePosGLFW3(GLFWwindow* /*window*/, double xpos, double ypos)
//{
//	TwMouseMotion(int(xpos), int(ypos));
//}
//inline void TwEventMouseWheelGLFW3(GLFWwindow* /*window*/, double /*xoffset*/, double yoffset)
//{
//	TwEventMouseWheelGLFW(yoffset);
//}
//inline void TwEventKeyGLFW3(GLFWwindow* /*window*/, int key, int /*scancode*/, int action, int /*mods*/)
//{
//	TwEventKeyGLFW(key, action);
//}
//inline void TwEventCharGLFW3(GLFWwindow* /*window*/, int codepoint)
//{
//	TwEventCharGLFW(codepoint, GLFW_PRESS);
//}
//inline void TwWindowSizeGLFW3(GLFWwindow* /*window*/, int width, int height)
//{
//	TwWindowSize(width, height);
//}
//
//void renderOrientation() {
//	if (!CCW) {
//		glFrontFace(GL_CCW);
//	}
//	else {
//		glFrontFace(GL_CW);
//	}
//}
//
//void renderModel() {
//	if (m_currentMesh == FILL) {
//		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//	}
//	else if (m_currentMesh == LINE) {
//		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//	}
//	else if (m_currentMesh == POINT) {
//		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
//	}
//}
//
//void TW_CALL ToggleNormalMapping(void /*clientData*/) {
//	isNorEnabled = !isNorEnabled;
//}
//
//void TW_CALL ToggleTexMapping(void /*clientData*/) {
//	isTexEnabled = !isTexEnabled;
//}
//
//void TW_CALL TogglePointLight(void /*clientData*/) {
//	ptLightEnable = !ptLightEnable;
//}
//
//void TW_CALL ToggleDirLight(void /*clientData*/) {
//	dirLightEnable = !dirLightEnable;
//}
////void bufferMode() {
////	if (zBuffering) {
////		//glEnable(GL_DEPTH_TEST);
////		glDepthFunc(GL_LESS);
////	}
////	else {
////		//glEnable(GL_DEPTH_TEST);
////		glDepthFunc(GL_ALWAYS);
////	}
////}
//
//
//void callATB(TwBar *bar, GLFWwindow *window) {
//
//	// Initialize AntTweakBar
//	TwInit(TW_OPENGL_CORE, NULL);
//
//	TwWindowSize(1024, 768);
//
//	// Create a tweak bar
//	bar = TwNewBar("TweakBar");
//
//	//// Add 'wire' to 'bar': it is a modifable variable of type TW_TYPE_BOOL32 (32 bits boolean). Its key shortcut is [w].
//	//TwAddVarRW(bar, "wire", TW_TYPE_BOOL32, &wire,
//	//	" label='Wireframe mode' key=w help='Toggle wireframe display mode.' ");
//
//	TwEnumVal Models[] = { { CUBE, "Cube" },{ CYBORG, "Cyborg" } };
//	TwType ModelTwType = TwDefineEnum("ModelType", Models, 2);
//	TwAddVarRW(bar, "Model", ModelTwType, &m_currentModel, NULL);
//
//	//TwEnumVal Rotation[] = { { NONE, "None" },{ X, "X" },{ Y, "Y" },{ Z, "Z" } };
//	//TwType RotationTwType = TwDefineEnum("Rotation", Rotation, 4);
//	//TwAddVarRW(bar, "Rotation", RotationTwType, &m_lightRotateAxes, NULL);
//
//	//TwAddVarRW(bar, "cameraPOS", TW_TYPE_DIR3F, &camPosition, " label='Camera position' ");
//
//	//TwAddVarRW(bar, "bgColor", TW_TYPE_COLOR3F, &bgColor, " label='Background color' ");
//
//	///*TwAddVarRW(bar, "glLightEnable", TW_TYPE_BOOL32, &glLightEnable, " label='glLightEnable' ");
//	//TwAddVarRW(bar, "lightColor", TW_TYPE_COLOR3F, &lightColor, " label='Light color' ");*/
//
//	//TwAddButton(bar, "ptLightEnable", (TwButtonCallback)TogglePointLight, NULL, " label='ptLightEnable' ");
//	//TwAddVarRW(bar, "ptDiffuseLightColor", TW_TYPE_COLOR3F, &ptDiffuseLightColor, " label='Pt Diffuse light color' ");
//	//TwAddVarRW(bar, "ptLightPOS", TW_TYPE_DIR3F, &ptLtPos, " label='Point Light position' ");
//
//	//TwAddButton(bar, "dirLightEnable", (TwButtonCallback)ToggleDirLight, NULL, " label='dirLightEnable' ");
//	//TwAddVarRW(bar, "dirDiffuseLightColor", TW_TYPE_COLOR3F, &dirDiffuseLightColor, " label='Dir Diffuse light color' ");
//	//TwAddVarRW(bar, "dirLightDir", TW_TYPE_DIR3F, &dirLtDir, " label='Dir Light direction' ");
//
//	///*TwEnumVal BoolBuff[] = { { ON, "On" },{ OFF, "Off" } };
//	//TwType BoolBuffTwType = TwDefineEnum("BoolBuffType", BoolBuff, 2);
//	//TwAddVarRW(bar, "zBuffering", BoolBuffTwType, &zBuffering, NULL);*/
//
//	///*TwEnumVal ShaderType[] = { { FLAT, "Flat" },{ SMOOTH, "Smooth" } };
//	//TwType ShaderTWType = TwDefineEnum("ShaderType", ShaderType, 2);
//	//TwAddVarRW(bar, "shaderType", ShaderTWType, &m_currentShader, NULL);*/
//
//	///*TwEnumVal Meshes[] = { { FILL, "Fill" },{ LINE, "Line" },{ POINT, "Point" } };
//	//TwType MeshTwType = TwDefineEnum("MeshType", Meshes, 3);
//	//TwAddVarRW(bar, "Mesh", MeshTwType, &m_currentMesh, NULL);*/
//
//	//TwAddButton(bar, "resetCam", (TwButtonCallback)DefCam, NULL, " label='Reset Camera' ");
//	//TwAddButton(bar, "resetPtLight", (TwButtonCallback)DefPtLight, NULL, " label='Reset Point Light' ");
//	//TwAddButton(bar, "resetDirLight", (TwButtonCallback)DefDirLight, NULL, " label='Reset Dir Light' ");
//	//TwAddButton(bar, "nor", (TwButtonCallback)ToggleNormalMapping, NULL, " label='Normal On?' ");
//	//TwAddButton(bar, "tex", (TwButtonCallback)ToggleTexMapping, NULL, " label='Texture On?' ");
//
//	// Set GLFW event callbacks
//	// - Directly redirect GLFW mouse button events to AntTweakBar
//	glfwSetMouseButtonCallback(window, (GLFWmousebuttonfun)TwEventMouseButtonGLFW3);
//	glfwSetCursorPosCallback(window, (GLFWcursorposfun)TwEventMousePosGLFW3);
//	glfwSetScrollCallback(window, (GLFWscrollfun)TwEventMouseWheelGLFW3);
//	glfwSetKeyCallback(window, (GLFWkeyfun)TwEventKeyGLFW3);
//	glfwSetCharCallback(window, (GLFWcharfun)TwEventCharGLFW3);
//
//}
//
//#endif TWEAKBAR_H