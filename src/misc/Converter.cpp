#include "Converter.hpp"

#include <sstream>
#include <cmath>
#include <assert.h>
#include <iostream>
#include <string.h>

#include "Debug.hpp"

int Converter::stringToInt(const std::string& s)
{
	return atoi(s.c_str());
}

float Converter::stringToFloat(const std::string& s)
{
	return std::stof(s);
}

std::string Converter::intToString(int i)
{
	std::stringstream s;
	s << i;
	return s.str();
}

std::string Converter::floatToString(float i)
{
	std::stringstream s;
	s << i;
	return s.str();
}

std::string Converter::floatToStringPrecise(float f, int precision)
{
	char buffer[precision];
	precision = std::min(67, precision);
	sprintf(buffer, "%.*e", (int)(precision-1), f);

	int counter = precision;

	while (buffer[counter] == '0')
	{
		counter--;
	}

	counter++;

	if (counter != precision-4)
	{
		char buffer2[counter+5];
		int i;
		for (i = 0; i < counter; i++)
		{
			buffer2[i] = buffer[i];
		}
		for (int j = precision+1; j < precision+5; j++)
		{
			buffer2[i] = buffer[j];
			i++;
		}
		buffer2[counter+4] = '\0';
		return buffer2;
	}

	return buffer;
}

std::string Converter::charsToString(const std::string& arg)
{
	std::string res = "(";
	for (unsigned int i = 0; i < arg.size(); i++)
	{
		res += intToString((int)arg[i]) + ((i != arg.size()-1)?", ":"");
	}
	return res + ")";
}

std::string Converter::boolToString(bool b)
{
	return b ? "true" : "false";
}

bool Converter::isValidFloat(float f)
{
	return std::isfinite(f);
}
