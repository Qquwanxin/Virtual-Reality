/*
SJTU - CS230/CS238: Virtual Reality

Homework 1: Hello Teapot

Tasks:

1. compile and get to run
2. wireframe teapot
3. write mouse and keyboard interaction

	Egemen Ertugrul
	egertu@sjtu.edu.cn

*/

//-----------------------------------------------------------------------------
// includes

#include <stdio.h>
#include <cstdlib>
#include <sdlWrapper.h>
#include <shader.h>
#include <glm\glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <model.h>

#undef main // Needed because SDL defines its own main
#ifdef WIN32
	#include <windows.h>
#endif

using namespace std;
using namespace glm;
#define PI 3.1415926535
//-----------------------------------------------------------------------------
// some global variables

// Relative path to source files
std::string codeDir = "../";

// Relative path to models directory
std::string modelsDir = codeDir + "models/";

// flag to check if render wireframe or filled
bool	bWireframe = true;

// near clipping plane
float	zNear = 1.0;

// far clipping plane
float	zFar = 100000.0;

// Function Declarations
bool handleEvents(SDL_Event & evt, sdlWrapper & sdlContext);

// ****************************************************************************
// ************            Insert your code here                   ************
// ****************************************************************************

// You can use these global variables to start thinking about how to implement mouse movements
// You do not have to use these if you don't want



// parameters for the navigation
glm::vec3	viewerPosition	(0.0f , 0.0f, 50.0f);
glm::vec3	viewerCenter	(0.0, 0.0, 0.0);
glm::vec3	viewerUp		(0.0, 1.0, 0.0);

// rotation values for the navigation
float	navigationRotation[3] = { 0.0, 0.0, 0.0 };

// position of the mouse when pressed
int		mousePressedX = 0, mousePressedY = 0;
float	lastXOffset = 0.0, lastYOffset = 0.0, lastZOffset = 0.0;
// mouse button states
int		leftMouseButtonActive = 0, middleMouseButtonActive = 0, rightMouseButtonActive = 0;
float posx = 0.0, posy = 0.0, poxz = 0.0;//the postion of all
float mpx, mpy, mpxx, mpyy;//position of the mouse when pressed;
float xRot = 0.0, yRot = 0.0;//转动的角度
// ****************************************************************************
// ****************************************************************************
// ****************************************************************************


//---------------------------------------------------------------
// main function
//---------------------------------------------------------------

void main(int argc, char **argv) {
	
	sdlWrapper sdlContext(1280, 960, "Hello World", 0, false);
	SDL_Event evt;

	float aspectRatio = (float)sdlContext.getWidth() / (float)sdlContext.getHeight();

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	printf("EE 267 HW1\n\n");
	printf("keys:\n\tf\t- toggle fullscreen\n\tesc\t- exit\n\n");
	printf("mouse:\n\tleft button\t- rotation\n\tmiddle button\t- panning\n\tright button\t- zoom in and out\n");

	// Shader class instantiation
	Shader shader("../shaders/vertexShader.glsl", "../shaders/fragShader.glsl");
	Shader shader2("../shaders/vertexShader.glsl", "../shaders/fragShader.glsl");
	Shader shader3("../shaders/vertexShader.glsl", "../shaders/fragShader.glsl");
	// ****************************************************************************
	// ************************* Load Your Models Here ****************************
	// ****************************************************************************
	std::cout << "Loading Models ...";
	Model model(modelsDir + "teapot.obj");
	Model axes(modelsDir + "axes.obj");
	Model cat(modelsDir + "cat.obj");
	Model deer(modelsDir + "deer.obj");
	std::cout << " Done!" << std::endl;
	// ****************************************************************************
	// ****************************************************************************
	// ****************************************************************************


	// Main rendering loop
	bool running = true;
	while (running) {

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		running = handleEvents(evt, sdlContext);

		glViewport(0, 0, sdlContext.getWidth(), sdlContext.getHeight());

		// Always call this before you attach something to uniform, or initiate any draw calls
		shader.Use();
		shader2.Use();
		
		// ****************************************************************************
		// ************************** Insert your Code here ***************************
		// ****************************************************************************
		glm::vec3	viewerPosition(50*sin(xRot), 50 * sin(yRot) , 50.0f*cos(xRot)*cos(yRot));
		//cout << 50 * sin(xRot) << "  " << 50 * sin(yRot) << " " << 50.0f*cos(xRot)*cos(yRot) << endl;

		// Setup Projection, Model, and View Matricies
		glm::mat4 projMat = glm::perspective(glm::radians(50.0f), aspectRatio, zNear, zFar);
		glm::vec3 teapotPos = glm::vec3(0.0f+posx, 0.0f+posy, 0.0f+poxz);
		glm::mat4 modelMat = glm::scale(glm::translate(glm::mat4(1.0f), teapotPos), glm::vec3(7.0f));
		glm::mat4 viewMat = glm::lookAt(viewerPosition, viewerCenter, viewerUp);

		// Attached Projection, Model, and View matricies to the shader
		// In the shader the Proj * View * Model * vertex_coord operation is carried out
		shader.attachToUniform("Proj", projMat);
		shader.attachToUniform("View", viewMat);
		shader.attachToUniform("Model", modelMat);

		glm::mat4 projMat2 = glm::perspective(glm::radians(50.0f), aspectRatio, zNear, zFar);
		glm::vec3 teapotPos2 = glm::vec3(17.0f + posx, -3.0f + posy, 0.0f + poxz);
		glm::mat4 modelMat2 = glm::scale(glm::translate(glm::mat4(1.0f), teapotPos2), glm::vec3(0.015f));
		glm::mat4 viewMat2 = glm::lookAt(viewerPosition, viewerCenter, viewerUp);
		
		shader2.attachToUniform("Proj", projMat2);
		shader2.attachToUniform("View", viewMat2);
		shader2.attachToUniform("Model", modelMat2);

		glm::mat4 projMat3 = glm::perspective(glm::radians(50.0f), aspectRatio, zNear, zFar);
		glm::vec3 teapotPos3 = glm::vec3(-10.0f + posx, -3.0f + posy, 0.0f + poxz);
		glm::mat4 modelMat3 = glm::scale(glm::translate(glm::mat4(1.0f), teapotPos3), glm::vec3(0.01f));
		glm::mat4 viewMat3 = glm::lookAt(viewerPosition, viewerCenter, viewerUp);

		shader3.attachToUniform("Proj", projMat3);
		shader3.attachToUniform("View", viewMat3);
		shader3.attachToUniform("Model", modelMat3);
		
		axes.Draw(shader);
		model.Draw(shader);
		cat.Draw(shader2);
		deer.Draw(shader3);


		// ****************************************************************************
		// ****************************************************************************
		// ****************************************************************************
		
		sdlContext.swapbuffer();
	}

		
}

//**************************************************************
// SDL event handler function
//**************************************************************

bool handleEvents(SDL_Event & evt, sdlWrapper & sdlContext) {

	// Poll all events that have occurred
	while (SDL_PollEvent(&evt)) {
		// If Quit ( X in window is pressed)
		if (evt.type == SDL_QUIT) {
			return false;
		}

		// Handle Keyboard events
		if (evt.type == SDL_KEYDOWN) {
			// Quit if escape key is pressed
			if (evt.key.keysym.sym == SDLK_ESCAPE) {
				return false;
			}

			// Toggle Fullscreen
			if (evt.key.keysym.sym == SDLK_f) {
				sdlContext.toggleFullScreen();
			}

			// Toggle Wireframe
			if (evt.key.keysym.sym == SDLK_w) {
				if (bWireframe) {
					glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
					bWireframe = false;
				}
				else {
					glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
					bWireframe = true;
				}
			}
		}

		// ****************************************************************************
		// ************************** Insert your Code here ***************************
		// ****************************************************************************

		// Handle Mouse Click Events
		if (evt.type == SDL_MOUSEBUTTONDOWN) {
			switch (evt.button.button) {
			//case SDL_BUTTON_LEFT: {leftMouseButtonActive = 1; mousePressedX = evt.motion.x; mousePressedY = evt.motion.y;   break; }
			//case SDL_BUTTON_RIGHT: {rightMouseButtonActive = 1; mousePressedX = evt.motion.x;  mousePressedY = evt.motion.y; break; }
			//case SDL_BUTTON_MIDDLE: {middleMouseButtonActive = 1; mousePressedX = evt.motion.x;  mousePressedY = evt.motion.y; break; }
			case SDL_BUTTON_LEFT: {leftMouseButtonActive = 1; mpx = evt.motion.x; mpy = evt.motion.y;   break;}
			case SDL_BUTTON_RIGHT: {rightMouseButtonActive = 1; mpx = evt.motion.x;  break; }
			case SDL_BUTTON_MIDDLE: {middleMouseButtonActive = 1; mpx = evt.motion.x;  mpy = evt.motion.y; break; }
			}
		}

		if (evt.type == SDL_MOUSEBUTTONUP) {
			switch (evt.button.button) {
			case SDL_BUTTON_LEFT: {leftMouseButtonActive = 0;  break; }
			case SDL_BUTTON_RIGHT: {rightMouseButtonActive = 0;break; }
			case SDL_BUTTON_MIDDLE: {middleMouseButtonActive = 0; break; }
			}
		}

		// Handle Mouse Motion Events
		if (evt.type == SDL_MOUSEMOTION) {
			if (middleMouseButtonActive == 1)
			{
				mpxx = evt.motion.x;  mpyy = evt.motion.y;
				posx += (mpxx - mpx) / 20;
				posy += (mpy - mpyy) / 20;
				mpx = mpxx;
				mpy = mpyy;
			}
			if (rightMouseButtonActive == 1) {
				mpxx = evt.motion.x;
				poxz += (mpxx - mpx) / 20;
				mpx = mpxx;
			}
			if (leftMouseButtonActive == 1)
			{
				mpxx = evt.motion.x;  mpyy = evt.motion.y;
				xRot += (mpx - mpxx)/300;
				yRot += (mpyy - mpy) /300;
				mpx = mpxx;
				mpy = mpyy;
				//cout << xRot/PI<<"  "<< yRot / PI << endl;
			}
		}
		
		// ****************************************************************************
		// ****************************************************************************
		// ****************************************************************************
	}
	return true;
}

