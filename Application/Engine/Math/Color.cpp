#include "pch.h"
#include "Color.h"

namespace nc
{
	Color const Color::white{ 1,1,1 };
	Color const Color::red{ 1,0,0 };
	Color const Color::green{ 0,1,0 };
	Color const Color::blue{ 0,0,1 };

	std::istream& operator>> (std::istream& stream, Color& c)
	{
		std::string line;
		std::getline(stream, line);

		if (line.find("{") != std::string::npos)
		{
			//r
		std::string cr = line.substr(line.find("{") + 1, line.find(",") - line.find("{") - 1);
		c.r = std::stof(cr);
		line = line.substr(line.find(",") + 1, line.find("}") - line.find(",") -1);

			//g
		std::string cg = line.substr(0, line.find(","));
		c.g = std::stof(cg);
			//b
		std::string cb = line.substr(line.find(",") + 1, line.find("}") - line.find(",")-1);
		c.b = std::stof(cb);
		}
		return stream;
	}
	std::ostream& operator<<(std::ostream& stream, Color& c)
	{
		stream << c.r << " " << c.g << " " << c.b << " " << c.a;

		return stream;
	}
}