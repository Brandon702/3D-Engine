#include "pch.h"

void _assert(bool condition, const std::string& conditionString, const std::string& filename, int line, const std::string& functionName, const std::string& message)
{
	if (condition == false)
	{
		std::cout << "assertion failed: " << conditionString << std::endl;
		if (message.empty())
		{
			std::cout << message << std::endl;
		}
		std::cout << "file: " << filename << std::endl;
		std::cout << "function: " << functionName << std::endl;
		std::cout << "line: " << line << std::endl;

		abort();
	}
}
