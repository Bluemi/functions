#ifndef __CONVERTER_CLASS__
#define __CONVERTER_CLASS__

#include <SFML/Graphics/Color.hpp>
#include <string>

class Converter
{
	public:
		static int stringToInt(const std::string&);
		static float stringToFloat(const std::string&);
		static std::string intToString(int);
		static std::string floatToString(float);
		static std::string floatToStringPrecise(float, int=4);
		static std::string charsToString(const std::string&);
		static std::string boolToString(bool);
		static bool isValidFloat(float);
};

#endif
