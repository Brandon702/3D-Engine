#include "pch.h"
#include "VertexIndexArray.h"

namespace nc
{
	bool VertexIndexArray::Create(const std::string& name, void* null)
	{
		VertexArray::Create(name, null);

		return true;
	}

	void VertexIndexArray::Destroy()
	{
		VertexArray::Destroy();

		glDeleteBuffers(1, &m_ibo);
	}


	void VertexIndexArray::CreateIndexBuffer(GLenum indexType, GLsizei count, void* data)
	{
		m_indexType = indexType;
		m_indexCount = count;

		glGenBuffers(1, &m_ibo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
		size_t indexSize = (m_indexType == GL_UNSIGNED_SHORT) ? sizeof(GLushort) : sizeof(GLuint);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * indexSize, data, GL_STATIC_DRAW);
	}

	void VertexIndexArray::Draw(GLenum primitiveType)
	{
		glBindVertexArray(m_vao);
		glDrawElements(primitiveType, m_indexCount, m_indexType, 0);
	}
}
