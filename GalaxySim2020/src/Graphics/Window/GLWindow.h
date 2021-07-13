#pragma once
#include "Corepch.h"
#include <GLFW/glfw3.h>
#include "Window.h"
#include "Event/BaseClasses/EventDispatcher.h"
#include "OpenglContext.h"

namespace Graphics {
#define DEFAULT_ASP_HORIZONTAL 16
#define DEFAULT_ASP_VERTICAL 9
#define DEFAULT_SIZE_X 1920
#define DEFAULT_SIZE_Y 1080
	class GLWindow : public IWindow, public IOpenglContext {
	private:
		GLFWwindow* window;
		std::string title;
		
	public:
		GLWindow(std::string title, std::shared_ptr<Application::EventDispatcher> dispatcher, int32_t sizeX = DEFAULT_SIZE_X, int32_t sizeY = DEFAULT_SIZE_Y, bool fullscreen = false);
		GLFWwindow* getWindow();
		void pollEvents () override;
		void makeOGLContextCurrent () override;
		void paint () override;

	};
}