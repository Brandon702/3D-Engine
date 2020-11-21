#include "pch.h"
#include "Renderer.h"
#include <glad/glad.h>

bool nc::Renderer::Startup()
{
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return false;
	}
	//IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
	return true;
}

void nc::Renderer::Shutdown()
{
	SDL_GL_DeleteContext(m_context);
	SDL_DestroyWindow(m_window);
}

void nc::Renderer::Update()
{

}

bool nc::Renderer::Create(const std::string& name, int width, int height)
{
	m_window = SDL_CreateWindow(name.c_str(), 100, 100, width, height, SDL_WINDOW_OPENGL);
	if (m_window == nullptr)
	{
		SDL_Log("Failed to create window: %s", SDL_GetError());
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
	//SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
	SDL_GL_SetSwapInterval(1);

	m_context = SDL_GL_CreateContext(m_window);
	if (!gladLoadGL())
	{
		SDL_Log("Failed to create OpenGL context");
		exit(-1);
	}
}

void nc::Renderer::BeginFrame()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
}

void nc::Renderer::EndFrame()
{
	SDL_GL_SwapWindow(m_window);
}
