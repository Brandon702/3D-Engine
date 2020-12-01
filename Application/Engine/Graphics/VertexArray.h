#pragma once
#include "..\Resources\Resource.h"
#include <vector>

namespace nc
{
	class VertexArray : public Resource
	{
	public:
		bool Create(const std::string& name, void* null = nullptr) override;
		void Destroy() override;

		void CreateBuffer(GLsizei size, GLsizei count, void* data);
		void SetAttribute(int index, GLint size, GLsizei stride, size_t offset);

		virtual void Draw(GLenum primitiveType = GL_TRIANGLES);

		void Bind() { glBindVertexArray(m_vao); }

	protected:
		GLuint m_count = 0;

		GLuint m_vao = 0;
		std::vector<GLuint> m_vbos;
	};
}