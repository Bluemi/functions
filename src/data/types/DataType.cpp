#include "DataType.hpp"

#include <misc/Debug.hpp>
#include <misc/Converter.hpp>

unsigned int getTypeSize(const DataType& t)
{
	switch (t)
	{
		case DataType::INT:
			return sizeof(int);
		case DataType::FLOAT:
			return sizeof(float);
		case DataType::BOOL:
			return sizeof(bool);
		case DataType::UNDEFINED:
			Debug::warn("DataPattern::getTypeSize(): type=UNDEFINED");
			return 0;
	}
	Debug::error("DataType::getTypeSize(): invalid type = " + Converter::intToString(t));
	return 0;
}

std::string getTypeName(const DataType t)
{
	switch (t)
	{
		case DataType::INT:
			return "INT";
		case DataType::FLOAT:
			return "FLOAT";
		case DataType::BOOL:
			return "BOOL";
		case DataType::UNDEFINED:
			return "UNDEFINED";
	}
	Debug::warn("Unknown DataType: " + Converter::intToString(t));
	return "";
}

bool matches(const DataType& a, const DataType& b)
{
	if (a == DataType::UNDEFINED)
	{
		return false;
	}
	return (a == b);
}
