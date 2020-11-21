#pragma once

#include "../Resources/Resource.h"
#include <string>
#include <SDL.h>

namespace nc
{
	class Texture : public Resource
	{
	public:
		bool Create(const std::string& name, void* null) override;
		void Destroy() override;

		bool CreateTexture(const std::string& filename, GLenum target = GL_TEXTURE_2D, GLuint unit = GL_TEXTURE0);

	protected:
		GLenum m_target{ GL_TEXTURE_2D };
		GLuint m_unit{ GL_TEXTURE0 };
		GLuint m_texture{ 0 };
	};
}
