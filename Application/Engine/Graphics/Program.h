#pragma once
#include "../Resources/Resource.h"

namespace nc
{
	class Program : public Resource
	{
	public:
		bool Create(const std::string& name, void* null) override;
		void Destroy() override;

		void CreateShaderFromFile(const std::string& filename, GLenum shader_type);
		void CreateShaderFromSource(const std::string& source, GLenum shader_type);

		void Link();
		void Use();

		GLuint GetProgramID() { return m_program; }
		bool IsLinked() { return m_linked; }

		void SetUniform(const std::string& name, float x, float y, float z);
		void SetUniform(const std::string& name, const glm::vec2& v2);
		void SetUniform(const std::string& name, const glm::vec3& v3);
		void SetUniform(const std::string& name, const glm::vec4& v4);
		void SetUniform(const std::string& name, const glm::mat4& mx4);
		void SetUniform(const std::string& name, const glm::mat3& mx3);
		void SetUniform(const std::string& name, float value);
		void SetUniform(const std::string& name, int value);
		void SetUniform(const std::string& name, bool value);
		void SetUniform(const std::string& name, GLuint value);

	private:
		GLint GetUniform(const std::string& name);

	private:
		GLuint m_program{ 0 };
		bool m_linked{ false };
		std::map<std::string, GLuint> m_uniforms;
	};
}
