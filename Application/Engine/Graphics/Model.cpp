#include "pch.h"
#include "Model.h"

namespace nc
{
	bool Model::Load(const std::string& filename,
		std::vector<glm::vec3>& positions,
		std::vector<glm::vec3>& normals,
		std::vector<glm::vec2>& texcoords)
	{
		std::vector<glm::vec3> model_positions;
		std::vector<glm::vec3> model_normals;
		std::vector<glm::vec2> model_texcoords;

		std::ifstream stream(filename, std::ios::binary);
		if (!stream.is_open())
		{
			SDL_Log("Error opening model file: %s", filename.c_str());
			return false;
		}

		std::string line;
		while (std::getline(stream, line))
		{
			// code
		}


		return true;
	}
}
