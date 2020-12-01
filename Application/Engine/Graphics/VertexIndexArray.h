#pragma once
#include "VertexArray.h"

namespace nc
{
	class VertexIndexArray : public VertexArray
	{
	public:
		bool Create(const std::string& name, void* null = nullptr) override;
		void Destroy() override;

		void CreateIndexBuffer(GLenum indexType, GLsizei count, void* data);

		void Draw(GLenum primitiveType = GL_TRIANGLES) override;

	protected:
		GLuint m_ibo = 0;
		GLuint m_indexCount = 0;
		GLenum m_indexType = 0;
	};
}
